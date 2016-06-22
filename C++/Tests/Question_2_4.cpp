#include <gtest/gtest.h>
#include "LinkedList.h"

// 2.4 Write code to partition a linked list around a value x, such that all nodes less than x
// come before alt nodes greater than or equal to x

template<typename T>
void LinkedList<T>::PartitionList(T value)
{
    Node<T> *lesser = nullptr;
    Node<T> *higher = nullptr;
    Node<T> *middle = nullptr;

    auto tmp = root;
    while (tmp != nullptr)
    {
        auto next = tmp->Next();
        if (tmp->Data() < value)
        {
            tmp->Next(lesser);
            if (lesser == nullptr)
                lesser = middle = tmp;
            else
                lesser = tmp;
        }
        else
        {
            tmp->Next(higher);
            higher = tmp;
        }
        tmp = next;
    }

    middle->Next(higher);
    root = lesser;
}

TEST(Question_2_4, PartitionLinkedList)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(6);
    linkedList.AddNodeAtStart(5);
    linkedList.AddNodeAtStart(7);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(3);
    linkedList.PartitionList(5);
    auto result = linkedList.GetValues();
    std::vector<int> expected = { 2, 3, 6, 5, 7 };
    for (size_t i = 0; i < expected.size(); ++i)
        ASSERT_EQ(result[i], expected[i]);
}
