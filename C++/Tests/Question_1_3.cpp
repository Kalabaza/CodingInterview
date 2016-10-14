#include <string>
#include <gtest/gtest.h>

//? Question 1.3:
// Given two strings, write a method to decide if one is a permutation of the other.

// The method will modify the local copy of the strings (parameters passed by value).
bool IsPermutation(std::string str1, std::string str2)
{
    // If the size is not the same then it means that a permutation is not possible.
    if (str1.size() != str2.size())
        return false;

    // First sort the two strings (the sort will be done in place).
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Now compare the two strings, if they are equal then the original strings are a permutation.
    return str1.compare(str2) == 0 ? true : false;
}

//! Valid string permutation.
TEST(Question_1_3, StringPermutation)
{
    std::string str1{ "stressed" };
    std::string str2{ "desserts" };
    ASSERT_TRUE(IsPermutation(str1, str2));
}

//! Strings with different casing, (lower or upper case).
TEST(Question_1_3, StringPermutationDifferentCasing)
{
    std::string str1{ "Stressed" };
    std::string str2{ "Desserts" };
    ASSERT_FALSE(IsPermutation(str1, str2));
}

//! Not a valid string permutation, different size.
TEST(Question_1_3, StringPermutationDifferentSize)
{
    std::string str1{ "a" };
    std::string str2{ "string" };
    ASSERT_FALSE(IsPermutation(str1, str2));
}

//! Comparing two empty strings.
TEST(Question_1_3, EmptyStringPermutation)
{
    std::string str1{ "" };
    std::string str2{ "" };
    ASSERT_TRUE(IsPermutation(str1, str2));
}
