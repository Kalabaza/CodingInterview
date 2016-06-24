#include <gtest/gtest.h>
#include "Stack.h"

// 3.4 In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks sorted
// in ascending order of size from top to bottom (i.e., each disk sits on top of an
// even larger one). You have the following constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto the next tower.
// (3) A disk can only be placed on top of a larger disk.
// Write a program to move the disks from the first tower to the last using stacks.

template<typename T>
void MoveDisks(int n, Stack<T> &source, Stack<T> &target, Stack<T> &auxiliary)
{
    if (n > 0)
    {
        MoveDisks(n - 1, source, auxiliary, target);

        target.Push(source.Top());
        source.Pop();

        MoveDisks(n - 1, auxiliary, target, source);
    }
}

TEST(Question_3_4, TowerOfHanoi)
{
    Stack<int> A{ 5, 4, 3, 2, 1 };
    Stack<int> B;
    Stack<int> C;
    MoveDisks(5, A, C, B);
    Stack<int> D{ 5, 4, 3, 2, 1 };
    while(D.Size() != 0)
    {
        ASSERT_EQ(C.Top(), D.Top());
        C.Pop();
        D.Pop();
    }
}
