#include <gtest/gtest.h>
#include <limits>
#include "Stack.h"

// 3.2 How would you design a stack which, in addition to push and pop, also has a
// function min which returns the minimum element? Push, pop and min should
// all operate in O(1) time.

template<typename T>
class StackWithMin : public Stack<T>
{
private:
    Stack<T> min;

public:
    void Push(T data)
    {
        // Check if the new value is lower than the current min value.
        if (min.Empty() || data < min.Top())
            min.Push(data);

        Stack<T>::Push(data);
    }

    void Pop()
    {
        // Check if the value on the top is equal to the min value.
        if (Stack<T>::Top() == min.Top())
        {
            min.Pop();
        }
        Stack<T>::Pop();
    }

    T Min()
    {
        if (min.Empty())
            return std::numeric_limits<T>::max();
        else
            return min.Top();
    }
};

TEST(Question_3_2, MinMethodInStack)
{
    StackWithMin<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(7);
    stack.Push(0);
    ASSERT_EQ(0, stack.Min());
    stack.Pop();
    ASSERT_EQ(1, stack.Min());
}

TEST(Question_3_2, MinEmptyStack)
{
    StackWithMin<int> stack;
    ASSERT_EQ(std::numeric_limits<int>::max(), stack.Min());
}
