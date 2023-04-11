#include <iostream>
#include <GameEngineConsole/GameEngineArray.h>
#include <conio.h>

// 노드 형태
// 어떤 클래스가 자신 내부에 자기자신의 참조형(보통 포인터)을 n개 들고 있는 형태

typedef int DataType;

class Node
{
public:
    Node(const DataType& _Value)
        : Value(_Value)
    {
    }

    int GetValue()
    {
        return Value;
    }

    Node* GetNext()
    {
        return Next;
    }

    Node* GetPrev()
    {
        return Prev;
    }


    void NextLinkPointer(Node* _Next)
    {
        Next = _Next;
        _Next->Prev = this;
    }

    void NextLinkRef(Node& _Next)
    {
        Next = &_Next;
        _Next.Prev = this;
    }

private:
    // 단방향 노드
    Node* Next = nullptr;
    // 양방향
    Node* Prev = nullptr;

    DataType Value;
};

int main()
{
    Node Node1 = 0;
    Node Node2 = 1;
    Node Node3 = 2;
    Node Node4 = 3;
    Node Node5 = 4;

    Node1.NextLinkRef(Node2);
    Node2.NextLinkRef(Node3);
    Node3.NextLinkRef(Node4);
    Node4.NextLinkRef(Node5);

    Node* CurNode = &Node5;
    while (nullptr != CurNode)
    {
        printf_s("%d\n", CurNode->GetValue());
        CurNode = CurNode->GetPrev();
    }
}