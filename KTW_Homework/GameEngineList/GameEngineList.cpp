// 메모리는 연속되어있을 때 가장 빠름

// vector : 배열형 시퀸스 자료구조
// vector의 장점 : 메모리가 연속되어 있어 자료구조 중 가장 빠름
// vector의 단점 : 상황에 따른 너무나도 큰 재할당과 복사 연산의 위험성

// vector의 단점을 해결하기 위한 자료구조 : List
// List의 장점 : 편의성
// List의 단점 : 연산이 느림

#include <iostream>
#include <crtdbg.h>
#include <list>

typedef int DataType;

class GameEngineList
{
private:
    class ListNode
    {
    public:
        ListNode* Prev = nullptr;
        ListNode* Next = nullptr;
        DataType Value = 0;
    public:
        ~ListNode()
        {
            if (nullptr != Next)
            {
                delete Next;
                Next = nullptr;
            }
        }
    };

public:
    class iterator
    {
        friend GameEngineList;
    public:
        iterator()
        {

        }

        iterator(ListNode* _CurNode)
            : CurNode(_CurNode)
        {
            
        }

        bool operator!=(const iterator& _Other)
        {
            return CurNode != _Other.CurNode;
        }

        iterator& operator++()
        {
            CurNode = CurNode->Next;

            return *this;
        }

        DataType& operator*()
        {
            return CurNode->Value;
        }
    private:
        ListNode* CurNode = nullptr;
    };

    GameEngineList()
    {
        StartNode->Next = EndNode;
        EndNode->Prev = StartNode;
    }

    ~GameEngineList()
    {
        if (nullptr != StartNode)
        {
            delete StartNode;
            StartNode = nullptr;
        }
    }

    iterator begin()
    {
        return iterator(StartNode->Next);
    }

    iterator end()
    {
        return iterator(EndNode);
    }

    iterator erase(iterator& _DeleteNode)
    {
        ListNode* DeleteNode = _DeleteNode.CurNode;

        ListNode* PrevNode = DeleteNode->Prev;
        ListNode* NextNode = DeleteNode->Next;

        DeleteNode->Prev = nullptr;
        DeleteNode->Next = nullptr;

        if (nullptr != DeleteNode)
        {
            delete DeleteNode;
            DeleteNode = nullptr;
        }

        PrevNode->Next = NextNode;
        NextNode->Prev = PrevNode;

        return iterator(NextNode);
    }

    void push_back(const DataType& _Value)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Value;

        ListNode* PrevNode = EndNode->Prev;

        PrevNode->Next = NewListNode;
        EndNode->Prev = NewListNode;

        NewListNode->Next = EndNode;
        NewListNode->Prev = PrevNode;
    }

    void push_front(const DataType& _Value)
    {
        ListNode* NewListNode = new ListNode();
        NewListNode->Value = _Value;

        ListNode* NextNode = StartNode->Next;

        NextNode->Prev = NewListNode;
        StartNode->Next = NewListNode;

        NewListNode->Next = NextNode;
        NewListNode->Prev = StartNode;
    }

private:
    ListNode* StartNode = new ListNode();
    ListNode* EndNode = new ListNode();
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    GameEngineList NewList;

    NewList.push_front(678);
    NewList.push_front(59);
    NewList.push_front(5);

    GameEngineList::iterator Delete = NewList.begin();
    ++Delete;

    NewList.erase(Delete);
 
    GameEngineList::iterator Start = NewList.begin();
    GameEngineList::iterator End = NewList.end();

    for (; Start != End; ++Start)
    {
        printf_s("%d\n", *Start);
    } 
}