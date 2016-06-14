// Will be using Google test to ensure that the solutions are working correctly.
#include <gtest/gtest.h>

// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

// The solution will be assuming that the string will have only ASCII characters.
bool HasUniqueChars(const std::string &text)
{
    // If a string of more than 256 characters is received on the input it means that at least
    // one character is repeated.
    if (text.size() > 256)
        return false;

    // Considering that only ASCII characters are going to be received on the string
    // an array of 256 positions is enough to tell if there are any repeated chars 
    // in the input string. An array of booleans will be used and it will be initialized
    // to false.
    bool charArray[256] = {};

    // Take each letter of the input text and mark the position on the array for that
    // specific letter, if the position was already marked it means that a duplicated
    // character was found, access the chars by reference to avoid copying them.
    for (auto &c : text)
    {
        // If the character was already marked return false to indicate a repeated character
        // was found in the text.
        if (charArray[c] == true)
            return false;
        // Mark the position on the array for this specific character.
        charArray[c] = true;
    }

    // If there were not repeated characters, return true to indicate that there are no duplicates.
    return true;
}

// Test cases to ensure the solution to the question is correct, using Google test framework.

// Test for non repeated characters.
TEST(Question_1_1, NonRepeatedChars)
{
    std::string text{ "abcdefg" };
    ASSERT_TRUE(HasUniqueChars(text));
}

// Test for repeated characters.
TEST(Question_1_1, RepeatedChars)
{
    std::string text{ "abcdefgabcdefg" };
    ASSERT_FALSE(HasUniqueChars(text));
}

// Test for empty string.
TEST(Question_1_1, EmptyInputString)
{
    std::string text{};
    ASSERT_EQ(true, HasUniqueChars(text));
}
