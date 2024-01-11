#include <gtest/gtest.h>

#include "LinkedList.h"

// 2.3 Implement an algorithm to delete a node in the middle of a singly linked list, given
// only access to that node.

template <typename T>
void LinkedList<T>::DeleteNode(Node<T> *node) {
    // Check if at least the current and next node are valid to do the deletion.
    if (node == nullptr || node->Next() == nullptr) return;

    auto tmp = node->Next();
    node->Data(tmp->Data());
    node->Next(tmp->Next());
    delete tmp;
}

TEST(Question_2_3, DeleteSpecificNode) {
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(3);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(1);
    auto tmp = linkedList.GetNode(2);
    linkedList.DeleteNode(tmp);
    auto result = linkedList.GetValues();
    std::vector<int> expected = {1, 3};
    for (size_t i = 0; i < expected.size(); ++i) ASSERT_EQ(result[i], expected[i]);
}