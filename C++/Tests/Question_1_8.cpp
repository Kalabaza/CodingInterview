#include <gtest/gtest.h>

// 1.8 Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check If s2 is a rotation of s1
// using only one call to isSubstring(e.g., "waterbottLe" is a rotation of "erbottLewat").

bool IsRotation(std::string str1, std::string str2)
{
    if (str1.length() != str2.length())
        return false;

    str1 = str1 + str1;

    return str1.find(str2) != std::string::npos ? true : false;
}

TEST(Question_1_8, StringRotation)
{
    std::string str1{ "waterbottLe" };
    std::string str2{ "erbottLewat" };
    ASSERT_TRUE(IsRotation(str1, str2));
}
