#include <string>
#include <gtest/gtest.h>

//? Question 1.8:
// Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check If s2 is a rotation of s1
// using only one call to isSubstring(e.g., "waterbottLe" is a rotation of "erbottLewat").

bool IsRotation(std::string str1, std::string str2)
{
    // First check if the length of the two strings is different, meaning that there cannot be a
    // valid rotation if the lengths are different.
    if (str1.length() != str2.length())
        return false;

    // A rotation means that by doing the concatenation of str1 + str1 and then searching for str2
    // in this concatenated string finding it will mean that a str2 is just a rotation of str1.
    std::string str3 = str1 + str1;

    // Check if str2 is a substring of the new concatenated string str3.
    return str3.find(str2) != std::string::npos ? true : false;
}

//! Valid string rotation
TEST(Question_1_8, StringRotation)
{
    std::string str1{ "waterbottLe" };
    std::string str2{ "erbottLewat" };
    ASSERT_TRUE(IsRotation(str1, str2));
}
