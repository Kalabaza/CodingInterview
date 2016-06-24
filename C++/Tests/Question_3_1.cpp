#include <gtest/gtest.h>

// 3.1 Describe how you could use a single array to implement three stacks

enum Stacks
{
    A = 0,
    B,
    C
};

template<typename T>
class StackArray
{
private:
    static const int ARRAY_SIZE = 99;
    static const int NUM_STACKS = 3;

    // Stack 1 range [0, n/3)
    // Stack 2 range [n/3, n2/3)
    // Stack 3 range [n2/3, n)
    T stackArray[ARRAY_SIZE];
    int stackIndex[NUM_STACKS];

public:
    StackArray() : stackIndex{ -1, -1, -1} {}

    void PushIntoStack(Stacks stack, T value)
    {
        // Check if there are still open positions on the array
        if (stackIndex[stack] + 1 < ARRAY_SIZE / 3)
        {
            ++stackIndex[stack];
            stackArray[stack * ARRAY_SIZE / 3 + stackIndex[stack]] = value;
        } 
    }

    void PopFromStack(Stacks stack)
    {
        if (stackIndex[stack] != -1)
        {
            --stackIndex[stack];
        }
    }

    T TopFromStack(Stacks stack)
    {
        if (stackIndex[stack] != -1)
        {
            return stackArray[stack * ARRAY_SIZE / 3 + stackIndex[stack]];
        }
        return -1;
    }
};

TEST(Question_3_1, StacksWithArray)
{
    StackArray<int> stack;
    stack.PushIntoStack(A, 1);
    stack.PushIntoStack(B, 2);
    stack.PushIntoStack(C, 3);
    ASSERT_EQ(1, stack.TopFromStack(A));
    ASSERT_EQ(2, stack.TopFromStack(B));
    ASSERT_EQ(3, stack.TopFromStack(C));
}

TEST(Question_3_1, StacksWithArrayEmpty)
{
    StackArray<int> stack;
    ASSERT_EQ(-1, stack.TopFromStack(A));
    ASSERT_EQ(-1, stack.TopFromStack(B));
    ASSERT_EQ(-1, stack.TopFromStack(C));
}
