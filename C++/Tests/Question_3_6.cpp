#include <gtest/gtest.h>
#include "Stack.h"

// 3.6 Write a program to sort a stack in ascending order (with biggest items on top).
// You may use at most one additional stack to hold items, but you may not copy
// the elements into any other data structure (such as an array). The stack supports
// the following operations : push, pop, peek, and isEmpty.

template<typename T>
void SortStack(Stack<T> &stack)
{
    Stack<T> tmp;
    T data;

    // Arrange the elements in the temporary stack.
    while(!stack.Empty())
    {
        data = stack.Top();
        stack.Pop();
        while (!tmp.Empty() && tmp.Top() < data)
        {
            stack.Push(tmp.Top());
            tmp.Pop();
        }
        tmp.Push(data);
    }

    // Copy the arranged elements back to the original stack.
    while(!tmp.Empty())
    {
        stack.Push(tmp.Top());
        tmp.Pop();
    }
}

TEST(Question_3_6, SortStack)
{
    Stack<int> stack{ 5, 3, 2, 1, 4 };
    SortStack(stack);
    Stack<int> expected{ 1, 2, 3, 4, 5 };
    while (!expected.Empty())
    {
        ASSERT_EQ(stack.Top(), expected.Top());
        stack.Pop();
        expected.Pop();
    }
}
