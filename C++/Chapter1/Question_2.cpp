#include <gtest/gtest.h>

#include <algorithm>
#include <string>

/**
 * Question 1.2:
 * Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
 */

/**
 * The solution will modify the local copy of the strings (parameters passed by value).
 * @param  str1 The first string that will be compared.
 * @param  str2 The second string that will be compared.
 * @return      True if one string is a permutation of the other.
 */
bool IsPermutationOld(std::string str1, std::string str2) {
    /// If the size is not the same then it means that a permutation is not possible.
    if (str1.size() != str2.size()) {
        return false;
    }

    /// First sort the two strings (sort done in place).
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    /// Now compare the two strings, if they are equal then the original strings are a permutation.
    return str1 == str2;
}

/**
 * The solution will use the function is_permutation from the stl.
 * @param  str1 The first string that will be compared.
 * @param  str2 The second string that will be compared.
 * @return      True if one string is a permutation of the other.
 */
bool IsPermutation(const std::string &str1, const std::string &str2) {
    return std::is_permutation(str1.begin(), str1.end(), str2.begin(), str2.end());
}

/// Test for valid string permutation.
TEST(Question_2, StringPermutation) {
    std::string str1{"stressed"};
    std::string str2{"desserts"};
    ASSERT_TRUE(IsPermutation(str1, str2));
}

/// Test strings with different case, lower/upper case.
TEST(Question_2, StringPermutationDifferentCasing) {
    std::string str1{"Stressed"};
    std::string str2{"Desserts"};
    ASSERT_FALSE(IsPermutation(str1, str2));
}

/// Test for a not a valid string permutation, different size.
TEST(Question_2, StringPermutationDifferentSize) {
    std::string str1{"s"};
    std::string str2{"string"};
    ASSERT_FALSE(IsPermutation(str1, str2));
}

/// Test to compare two empty strings.
TEST(Question_2, EmptyStringPermutation) {
    std::string str1{""};
    std::string str2{""};
    ASSERT_TRUE(IsPermutation(str1, str2));
}
