#include <cmath>
#include <gtest/gtest.h>
#include "LinkedList.h"

// 2.5 You have two numbers represented by a linked list, where each node contains a
// single digit. The digits are stored in reverse order, such that the 1's digit is at the
// head of the list. Write a function that adds the two numbers and returns the sum
// as a linked list.

template<typename T>
void SumLinkedLists(LinkedList<int> &A, LinkedList<T> &B, LinkedList<T> &C)
{
    auto a = 0, b = 0, c = 0;

    // Get all the values from the first linked list.
    auto tmp = A.Root();
    auto exp = 0;
    while(tmp != nullptr)
    {
        a += tmp->Data() * static_cast<int>(std::pow(10.0, exp++));
        tmp = tmp->Next();
    }
    // Now get the values from the second linked list.
    tmp = B.Root();
    exp = 0;
    while (tmp != nullptr)
    {
        b += tmp->Data() * static_cast<int>(std::pow(10.0, exp++));
        tmp = tmp->Next();
    }
    c = a + b;

    // Now generate the new linked list with the result of the addition.
    while (c != 0)
    {
        auto d = c % 10;
        C.AddNodeAtEnd(d);
        c /= 10;
    }
}

TEST(Question_2_5, AddTwoLinkedList)
{
    LinkedList<int> A;
    A.AddNodeAtEnd(0);
    A.AddNodeAtEnd(2);
    A.AddNodeAtEnd(3);
    LinkedList<int> B;
    B.AddNodeAtEnd(7);
    B.AddNodeAtEnd(3);
    B.AddNodeAtEnd(8);
    LinkedList<int> C;
    SumLinkedLists(A, B, C);
    auto result = C.GetValues();
    std::vector<int> expected = { 7, 5, 1, 1 };
    for (size_t i = 0; i < expected.size(); ++i)
        ASSERT_EQ(result[i], expected[i]);
}
