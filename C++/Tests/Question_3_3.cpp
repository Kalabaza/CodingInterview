#include <gtest/gtest.h>
#include "Stack.h"

// 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack
// exceeds some threshold. Implement a data structure SetOfStacks that mimics
// this. SetOfStacks should be composed of several stacks and should create a
// new stack once the previous one exceeds capacity. SetOfStacks.push() and
// SetOfStacks.pop() should behave identically to a single stack(that is, pop()
// should return the same values as it would if there were just a single stack).

template<typename T>
class SetOfStacks
{
private:
    static const int NUM_STACKS = 5;
    static const int LIMIT_SIZE = 10;

    Stack<T> stacks[NUM_STACKS];
    unsigned cur;
public:
    SetOfStacks() : cur{ 0 } {}

    void Push(T data)
    {
        // Do not insert more than the limit of plates on the stack
        if (stacks[cur].Size() == LIMIT_SIZE)
            ++cur;
        stacks[cur].Push(data);
    }

    void Pop()
    {
        if (!stacks[cur].Empty())
        {
            stacks[cur].Pop();
            if (stacks[cur].Empty() && cur != 0)
                --cur;
        }
    }

    T Top()
    {
        return stacks[cur].Top();
    }
};

TEST(Question_3_3, ArrayOfStacks)
{
    SetOfStacks<int> stack;
    for(auto i = 1; i <= 15; ++i)
        stack.Push(i);
    for (auto i = 15; i > 0; --i)
    {
        ASSERT_EQ(i, stack.Top());
        stack.Pop();
    }
}
