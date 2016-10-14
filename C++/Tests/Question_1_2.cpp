#include <string>
#include <gtest/gtest.h>
#include "StringHelpers.h"

//? Question 1.2:
// Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

// Reverse a c-style string.
void ReverseCharArray(char *start)
{
    // If the pointer is not valid return.
    if (start == nullptr)
        return;
    
    // First find the end of the string.
    auto *end = start;
    // Advance one location until the end of string character is found.
    while (*end != '\0')
        ++end;
    // Get back one char since the last one was the end of string char.
    --end;
    // Swap the characters using the start and end pointers.
    while (start < end)
        SwapChars(start++, end--);
}

// The function will be reversing the string in place, without having to return anything.
void ReverseString(std::string &text)
{
    // Check if the string has more than one character or return otherwise.
    if (text.empty() || text.length() == 1)
        return;

    for (size_t i = 0; i < text.length() / 2; ++i)
    {
        // Swap the ith character with the (last - ith) character, meaning that the first and last
        // characters will be swap, then the second with the last minus one, etc.
        SwapChars(text[i], text[text.length() - 1 - i]);
    }
}

//! Reverse a char array with even number of characters (4 in this case).
TEST(Question_1_2, ReverseCharArrayEvenLength)
{
    char *text = new char[5]{ "abcd" };
    ReverseCharArray(text);
    // Convert the char array into a string to be able to compare the result with the expected value.
    ASSERT_EQ("dcba", std::string(text));
    delete[] text;
}

//! Reverse a char array with odd number of characters (5 in this case).
TEST(Question_1_2, ReverseCharArrayOddLength)
{
    char *text = new char[6]{ "abcde" };
    ReverseCharArray(text);
    // Convert the char array into a string to be able to compare the result with the expected value.
    ASSERT_EQ("edcba", std::string(text));
    delete[] text;
}

//! Reverse a string with even number of characters (4 in this case).
TEST(Question_1_2, ReverseStringEvenLength)
{
    std::string text{ "abcd" };
    ReverseString(text);
    ASSERT_EQ("dcba", text);
}

//! Reverse a string with odd number of characters (5 in this case).
TEST(Question_1_2, ReverseStringOddLength)
{
    std::string text{ "abcde" };
    ReverseString(text);
    ASSERT_EQ("edcba", text);
}

//! Try to reverse an empty string.
TEST(Question_1_2, ReverseEmptyString)
{
    std::string text{ "" };
    ReverseString(text);
    ASSERT_EQ("", text);
}
