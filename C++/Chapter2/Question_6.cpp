#include <gtest/gtest.h>

#include <vector>

#include "LinkedList.h"

// 2.7 Implement a function to check if a linked list is a palindrome.

template <typename T>
bool LinkedList<T>::IsPalindrome() {
    std::vector<T> content;
    auto tmp = root;
    // Get all the elements from the linked list.
    while (tmp != nullptr) {
        content.push_back(tmp->Data());
        tmp = tmp->Next();
    }
    // Now check the items to see if there's a palindrome in the linked list.
    for (size_t i = 0; i < content.size(); ++i) {
        if (content[i] != content[content.size() - 1 - i]) return false;
    }

    return true;
}

TEST(Question_2_7, PalindromeEvenElements) {
    LinkedList<char> linkedList;
    linkedList.AddNodeAtEnd('a');
    linkedList.AddNodeAtEnd('b');
    linkedList.AddNodeAtEnd('b');
    linkedList.AddNodeAtEnd('a');
    ASSERT_TRUE(linkedList.IsPalindrome());
}

TEST(Question_2_7, PalindromeOddElements) {
    LinkedList<char> linkedList;
    linkedList.AddNodeAtEnd('a');
    linkedList.AddNodeAtEnd('b');
    linkedList.AddNodeAtEnd('c');
    linkedList.AddNodeAtEnd('b');
    linkedList.AddNodeAtEnd('a');
    ASSERT_TRUE(linkedList.IsPalindrome());
}

TEST(Question_2_7, NoPalindromeEvenElements) {
    LinkedList<char> linkedList;
    linkedList.AddNodeAtEnd('a');
    linkedList.AddNodeAtEnd('b');
    ASSERT_FALSE(linkedList.IsPalindrome());
}

TEST(Question_2_7, NoPalindromeOddElements) {
    LinkedList<char> linkedList;
    linkedList.AddNodeAtEnd('a');
    linkedList.AddNodeAtEnd('b');
    linkedList.AddNodeAtEnd('c');
    ASSERT_FALSE(linkedList.IsPalindrome());
}