#include <gtest/gtest.h>

// Forward declaration, the method is on the lib file of the C++ project
bool hasUniqueChars(const std::string&);

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
