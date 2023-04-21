#pragma once

#include <GameEngineBase/GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
	KeyType first;
	ValueType second;

public:
	GameEnginePair()
		: first(0), second(0)
	{

	}

	GameEnginePair(const KeyType& _Key, const ValueType& _Value)
		: first(_Key), second(_Value)
	{

	}
};

// 설명 :
class GameEngineMap
{
public:

	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginePair Pair;

		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		void ChangeChild(MapNode* _OldChild, MapNode* _NewChild)
		{
			if (_OldChild == LeftChild)
			{
				LeftChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

			if (_OldChild == RightChild)
			{
				RightChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

		}

		void Detach()
		{
			MapNode* DetachParent = Parent;
			MapNode* DetachLeftChild = LeftChild;
			MapNode* DetachRightChild = RightChild;

			if (nullptr != DetachParent && this == DetachParent->RightChild)
			{
				DetachParent->RightChild = DetachRightChild;
				if (nullptr != DetachRightChild)
				{
					DetachRightChild->Parent = DetachParent;
				}
			}
			else if (nullptr != DetachParent && this == DetachParent->LeftChild)
			{
				DetachParent->LeftChild = DetachLeftChild;
				if (nullptr != DetachLeftChild)					
				{
					DetachLeftChild->Parent = DetachParent;
				}
			}
		}

		void Release()
		{
			if (nullptr == Parent)
			{
				return;
			}

			if (this == Parent->LeftChild)
			{
				Parent->LeftChild = nullptr;
				return;
			}

			if (this == Parent->RightChild)
			{
				Parent->RightChild = nullptr;
				return;
			}

		}

		MapNode* OverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first > ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;

				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}

			return ParentNode;
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				return RightChild->MinNode();
			}

			if (nullptr != Parent)
			{
				return OverParentNode();
			}

			return nullptr;
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->MinNode();
		}

		MapNode* UnderParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first < ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;

				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}

			return ParentNode;
		}

		MapNode* PrevNode()
		{
			if (nullptr != LeftChild)
			{
				return LeftChild->MaxNode();
			}

			if (nullptr != Parent)
			{
				return UnderParentNode();
			}

			return nullptr;
		}

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->MaxNode();
		}

		bool insert(MapNode* _NewNode)
		{
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->insert(_NewNode);
				}

				LeftChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					return RightChild->insert(_NewNode);
				}

				RightChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}

			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->find(_Key);
				}

				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					return RightChild->find(_Key);
				}

				return nullptr;
			}

			return this;
		}
	};

	class iterator
	{
		friend GameEngineMap;

	public:
		iterator()
			: Node(nullptr)
		{

		}


		iterator(class MapNode* _Node)
			: Node(_Node)
		{

		}

		GameEnginePair* operator->()
		{
			return &Node->Pair;
		}


		bool operator!=(const iterator& _Other) const
		{
			return Node != _Other.Node;
		}

		bool operator==(const iterator& _Other) const
		{
			return Node == _Other.Node;
		}

		iterator& operator++()
		{
			Node = Node->NextNode();

			return *this;
		}

		iterator& operator--()
		{
			Node = Node->PrevNode();

			return *this;
		}

	private:
		class MapNode* Node = nullptr;
	};

	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator();
	}

	iterator rbegin()
	{
		if (nullptr == Root)
		{
			return rend();
		}

		return iterator(Root->MaxNode());
	}

	iterator rend()
	{
		return iterator();
	}

	iterator erase(const iterator& _EraseIter)
	{
		if (_EraseIter == end())
		{
			MsgBoxAssert("앤드를 삭제하려고 했습니다.");
		}

		MapNode* CurNode = _EraseIter.Node;
		MapNode* ParentNode = CurNode->Parent;
		MapNode* RightChild = CurNode->RightChild;
		MapNode* LeftChild = CurNode->LeftChild;

		MapNode* ChangeNode = nullptr;
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())
		{
			CurNode->Release();
			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}

		if (nullptr != RightChild)
		{
			ChangeNode = RightChild->MinNode();
			ChangeNode->Detach();

			if (nullptr != ParentNode)
			{
				ParentNode->ChangeChild(CurNode, ChangeNode);
				ChangeNode->LeftChild = CurNode->LeftChild;
				if (nullptr != ChangeNode->LeftChild)
				{
					ChangeNode->LeftChild->Parent = ChangeNode;
				}
				ChangeNode->RightChild = CurNode->RightChild;
				if (nullptr != ChangeNode->RightChild)
				{
					ChangeNode->RightChild->Parent = ChangeNode;
				}
			}
			return ChangeNode;
		}
		else if (nullptr != LeftChild)
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeNode->Detach();

			if (nullptr != ParentNode)
			{
				ParentNode->ChangeChild(CurNode, ChangeNode);
				ChangeNode->LeftChild = CurNode->LeftChild;
				if (nullptr != ChangeNode->LeftChild)
				{
					ChangeNode->LeftChild->Parent = ChangeNode;
				}
				ChangeNode->RightChild = CurNode->RightChild;
				if (nullptr != ChangeNode->RightChild)
				{
					ChangeNode->RightChild->Parent = ChangeNode;
				}
			}
			return ChangeNode;
		}

		return NextNode;
	}

	iterator find(KeyType _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		MapNode* FindNode = Root->find(_Key);

		return iterator(FindNode);
	}

	bool insert(const GameEnginePair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new MapNode();
			Root->Pair = _Pair;
			return true;
		}

		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Pair;

		if (false == Root->insert(NewNode))
		{
			delete NewNode;
			NewNode = nullptr;
		}

		return true;
	}

	MapNode* Root = nullptr;
};

