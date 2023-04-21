#pragma once

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>

template <typename KeyType, typename ValueType>
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

template <typename KeyType, typename ValueType>
class GameEngineMap
{
public:

	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginePair<KeyType, ValueType> Pair;

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

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->MaxNode();
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->MinNode();
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

		void FirstOrder()
		{
			std::cout << Pair.first << std::endl;
			if (nullptr != LeftChild)
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->FirstOrder();
			}
		}

		void MidOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}
		}

		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}

			std::cout << Pair.first << std::endl;
		}

		void DeleteNode()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->DeleteNode();
			}
			if (nullptr != RightChild)
			{
				RightChild->DeleteNode();
			}

			MapNode* CurNode = this;

			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
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

		GameEnginePair<KeyType, ValueType>* operator->()
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
		MapNode* ChangeNodeParent = nullptr;
		MapNode* ChangeChild = nullptr;
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())
		{
			ParentNode->ChangeChild(CurNode, nullptr);
			delete CurNode;
			CurNode = nullptr;
			return NextNode;
		}

		if (nullptr != RightChild)
		{
			ChangeNode = RightChild->MinNode();
			ChangeNodeParent = ChangeNode->Parent;
			ChangeChild = ChangeNode->RightChild;
		}

		else if (nullptr != LeftChild)
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeNodeParent = ChangeNode->Parent;
			ChangeChild = ChangeNode->LeftChild;
		}

		if (nullptr != ChangeNodeParent)
		{
			ChangeNodeParent->ChangeChild(ChangeNode, ChangeChild);
		}

		else
		{
			Root = ChangeNode;
			ChangeNodeParent = nullptr;
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("ChangeNode가 null");
			return nullptr;
		}

		ParentNode->ChangeChild(CurNode, ChangeNode);

		ChangeNode->LeftChild = LeftChild;
		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
		}

		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
		}

		if (nullptr != CurNode)
		{
			delete CurNode;
			CurNode = nullptr;
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

	bool insert(const GameEnginePair<KeyType, ValueType>& _Pair)
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

	void FirstOrder()
	{
		Root->FirstOrder();
	}

	void MidOrder()
	{
		Root->MidOrder();
	}

	void LastOrder()
	{
		Root->LastOrder();
	}

	~GameEngineMap()
	{
		Root->DeleteNode();
	}

private:
	MapNode* Root = nullptr;
};

