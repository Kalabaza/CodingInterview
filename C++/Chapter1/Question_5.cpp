#include <gtest/gtest.h>

#include <string>

/**
 * Question 1.5:
 * One Way: There are three types of edits that can be performed on strings: insert a character, remove a character, or
 * replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
 */

/**
 * The solution will start with the smallest text and find the differences with the other text.
 * @param  str1 The first string that will be compared.
 * @param  str2 The second string that will be compared.
 * @return      True if the strings are one (or zero) edits away.
 */
bool oneEditAway(const std::string &str1, const std::string &str2) {
    const std::string &shorter = str1.size() < str2.size() ? str1 : str2;
    const std::string &longer = str1.size() < str2.size() ? str2 : str1;

    /// If the difference between the sizes is greater than one, then it is not possible to be one edit away.
    if (longer.size() - shorter.size() > 1) {
        return false;
    }

    /// If the size is the same, there can only be one difference.
    if (shorter.size() == longer.size()) {
        bool foundDifference = false;
        for (size_t index = 0; index < shorter.size(); ++index) {
            if (shorter[index] != longer[index]) {
                if (foundDifference) {
                    return false;
                }
                foundDifference = true;
            }
        }
        return true;
    }

    /// If the sizes are different, then there can only be one difference.

    return true;
}

/// The two strings are one edit away from each other
TEST(Question_5, OneEditAway) {
    std::string str1{"pale"};
    std::string str2{"ple"};
    ASSERT_TRUE(oneEditAway(str1, str2));
}

/// More than one edit away
TEST(Question_5, MoreThanOneEditAway) {
    std::string str1{"pales"};
    std::string str2{"ple"};
    ASSERT_FALSE(oneEditAway(str1, str2));
}

/// One edit and the same size
TEST(Question_5, OneEditSameSize) {
    std::string str1{"pale"};
    std::string str2{"bale"};
    ASSERT_TRUE(oneEditAway(str1, str2));
}

/// Two edits and the same size
TEST(Question_5, TwoEditsSameSize) {
    std::string str1{"pale"};
    std::string str2{"bake"};
    ASSERT_FALSE(oneEditAway(str1, str2));
}
