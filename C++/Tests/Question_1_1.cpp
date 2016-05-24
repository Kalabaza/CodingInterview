#include <gtest/gtest.h>
#include <string>

// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?

bool hasUniqueChars(const std::string &text)
{
    // Considering that only ASCII characters are going to be received on the string
    // an array of 256 positions is enough to tell if there are any repeated
    // chars in the input string.
    bool charArray[256] = {};

    // If more than 256 are received on the input string it means that at least one
    // character is repeated.
    if (text.size() >= 256)
        return false;

    // Take each letter of the input text and mark the position on the array for that
    // specific letter, if the position was already marked it means that a duplicated
    // character was found.
    for (auto &c : text)
    {
        // Return false to indicate that a character was repeated in the text.
        if (charArray[c] == true)
            return false;
        // Mark the position on the array.
        charArray[c] = true;
    }

    // If there was not a repeated character, return true.
    return true;
}

// Test cases to ensure the solution to the question is correct

// No characters are repeated
TEST(Question_1_1, NonRepeatedChars)
{
    std::string text{ "abcdefg" };
    ASSERT_EQ(true, hasUniqueChars(text));
}

// Repeated characters
TEST(Question_1_1, RepeatedChars)
{
    std::string text{ "abcdefgabcdefg" };
    ASSERT_EQ(false, hasUniqueChars(text));
}

// Empty string test
TEST(Question_1_1, EmptyInputString)
{
    std::string text{};
    ASSERT_EQ(true, hasUniqueChars(text));
}
