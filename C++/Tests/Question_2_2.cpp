#include <gtest/gtest.h>
#include "LinkedList.h"

// 2.2 Implement an algorithm to find the kth to last element of a singly linked list.

template<typename T>
Node<T> *LinkedList<T>::FindKthNode(int kth)
{
    // Check that the kth value is positive and at least 1, since the kth element from the end
    // will be treated as the last one.
    if (kth <= 0)
        return nullptr;

    auto p1 = root;
    auto p2 = root;

    // Move the p1 pointer kth positions ahead of the p2 pointer.
    while(kth-- != 0)
    {
        // Check if there are valid nodes while advancing.
        if (p1 == nullptr)
            return nullptr;
        p1 = p1->Next();
    }

    // Now move the two pointers and when the p1 pointer reaches the end the p2 pointer
    // will be kth positions behind it.
    while(p1 != nullptr)
    {
        p1 = p1->Next();
        p2 = p2->Next();
    }

    return p2;
}


TEST(Question_2_2, KthElementInLinkedList)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(5);
    linkedList.AddNodeAtStart(4);
    linkedList.AddNodeAtStart(3);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(1);
    auto result = linkedList.FindKthNode(2);
    ASSERT_EQ(result->Data(), 4);
}

TEST(Question_2_2, KthElementInSingleNodeLinkedList)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(1);
    auto result = linkedList.FindKthNode(1);
    ASSERT_EQ(result->Data(), 1);
}

TEST(Question_2_2, InvalidKthElementInLinkedList)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(1);
    auto result = linkedList.FindKthNode(2);
    ASSERT_EQ(result, nullptr);
}
