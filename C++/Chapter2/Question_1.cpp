#include <gtest/gtest.h>

#include <map>

#include "LinkedList.h"

// 2.1 Write code to remove duplicates from an unsorted linked list.

// To remove the duplicates, the list will be traversed once and as soon as one value is found
// it will be added to a map, later when that same value is found again the node will be removed
// from the linked list
template <typename T>
void LinkedList<T>::RemoveDuplicates() {
    std::map<T, int> occurrences;
    auto tmp = root;
    auto prev = tmp;
    while (tmp != nullptr) {
        if (occurrences.count(tmp->Data()) != 0) {
            prev->Next(tmp->Next());
            delete tmp;
            tmp = prev;
        } else {
            ++occurrences[tmp->Data()];
            prev = tmp;
        }
        if (tmp != nullptr) tmp = tmp->Next();
    }
}

TEST(Question_2_1, DuplicatesInLinkedList) {
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(5);
    linkedList.AddNodeAtStart(5);
    linkedList.AddNodeAtStart(4);
    linkedList.AddNodeAtStart(4);
    linkedList.AddNodeAtStart(3);
    linkedList.AddNodeAtStart(3);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(1);
    linkedList.AddNodeAtStart(1);
    linkedList.RemoveDuplicates();
    auto result = linkedList.GetValues();
    std::vector<int> expected = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < expected.size(); ++i) ASSERT_EQ(result[i], expected[i]);
}

TEST(Question_2_1, NonDuplicatesInLinkedList) {
    LinkedList<int> linkedList;
    linkedList.AddNodeAtStart(5);
    linkedList.AddNodeAtStart(4);
    linkedList.AddNodeAtStart(3);
    linkedList.AddNodeAtStart(2);
    linkedList.AddNodeAtStart(1);
    linkedList.RemoveDuplicates();
    auto result = linkedList.GetValues();
    std::vector<int> expected = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < expected.size(); ++i) ASSERT_EQ(result[i], expected[i]);
}
