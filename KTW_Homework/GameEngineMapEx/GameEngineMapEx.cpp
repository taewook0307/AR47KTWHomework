#include <map>
#include <string>

template <typename KeyType, typename ValueType>
class Pair
{
public:
    KeyType first;
    ValueType Second;
};

template <typename KeyType, typename ValueType>
class MyMap
{
private:
    class Node
    {
    private:
        Pair<KeyType, ValueType> NewPair;
    };

public:
    Node Root;
};

int main()
{
    std::map<int, std::string> AllActor;

    // AllActor의 first의 자료형 = int
    // AllActor의 second의 자료형 = std::string

    std::string& NewString = AllActor[0];

    /* 33번줄 코드의 의미
    std::map<int, std::string>::iterator FindIter = AllActor.find(0);

    if (AllActor.end() == FindIter)
    {
        AllActor.insert(std::make_pair(0, "abc"));
        FindIter = AllActor.find(0);
    }
    */
}