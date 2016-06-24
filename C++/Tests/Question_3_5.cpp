#include <gtest/gtest.h>
#include "Stack.h"

// 3.5 Implement a MyQueue class which implements a queue using two stacks.

template<typename T>
class MyQueue
{
private:
    // Stack 1 will be used for insertion, s2 will be used to get the oldest element.
    Stack<T> s1, s2;

    void MoveElements()
    {
        while (!s1.Empty())
        {
            s2.Push(s1.Top());
            s1.Pop();
        }
    }

    void MoveBackElements()
    {
        while (!s2.Empty())
        {
            s1.Push(s2.Top());
            s2.Pop();
        }
    }

public:
    void Push(T data)
    {
        if (!s2.Empty())
            MoveBackElements();
        s1.Push(data);
    }

    void Pop()
    {
        if (!s1.Empty())
        {
            MoveElements();
        }
        if (!s2.Empty())
            s2.Pop();
    }

    T Front()
    {
        if (!s1.Empty())
            MoveElements();
        if (!s2.Empty())
            return s2.Top();
        // If this point is reached, an exception must be thrown.
        throw std::logic_error("Stacks 1 and 2 are empty, there are no more elements.");
    }

    bool Emtpy()
    {
        return s1.Empty() || s2.Empty();
    }
};

TEST(Question_3_5, QueueWithStacks)
{
    MyQueue<int> queue;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    ASSERT_EQ(1, queue.Front());
    queue.Pop();
    ASSERT_EQ(2, queue.Front());
    queue.Pop();
    queue.Push(5);
    ASSERT_EQ(3, queue.Front());
    queue.Pop();
    ASSERT_EQ(4, queue.Front());
    queue.Pop();
    ASSERT_EQ(5, queue.Front());
    queue.Pop();
}
