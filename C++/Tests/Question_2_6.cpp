#include <gtest/gtest.h>
#include "LinkedList.h"

// 2.6 Given a circular linked list, implement an algorithm which returns the node at
// the beginning of the loop.

template<typename T>
Node<T> *LinkedList<T>::GetLoopStart()
{
    // Using the fast/slow runner technique find if there's a loop in the linked list.
    auto slow = root;
    auto fast = root;

    while(fast != nullptr && fast->Next() != nullptr)
    {
        // move the pointers in a difference phase.
        slow = slow->Next();
        fast = fast->Next()->Next();

        // if the two pointers are pointing to the same node, it means a loop was found.
        if (slow == fast)
            break;
    }

    // No cycle was found in the linked list, return nullptr as a value.
    if (fast == nullptr || fast->Next() == nullptr)
        return nullptr;

    // If the cycle was found, now find where that cycle begins.
    slow = root;
    while (slow != fast)
    {
        slow = slow->Next();
        fast = fast->Next();
    }

    return fast;
}

TEST(Question_2_6, CircularListLoop)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtEnd(3);
    linkedList.AddNodeAtEnd(7);
    linkedList.AddNodeAtEnd(0);
    linkedList.AddNodeAtEnd(1);
    linkedList.AddNodeAtEnd(5);
    auto loop = linkedList.GetNode(7);
    auto end = linkedList.GetNode(5);
    end->Next(loop);
    auto result = linkedList.GetLoopStart();
    ASSERT_EQ(loop, result);
    end->Next(nullptr);
}

TEST(Question_2_6, NoCircularListLoop)
{
    LinkedList<int> linkedList;
    linkedList.AddNodeAtEnd(3);
    linkedList.AddNodeAtEnd(7);
    linkedList.AddNodeAtEnd(0);
    linkedList.AddNodeAtEnd(1);
    linkedList.AddNodeAtEnd(5);
    auto result = linkedList.GetLoopStart();
    ASSERT_EQ(nullptr, result);
}
