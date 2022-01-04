#include <string>
#include <gtest/gtest.h>

//? Question 1.3:
// Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a character array so that you can
// perform this operation in place.)

void URLify(std::string &text, int size)
{
    // first count the number of spaces in the text
    int spaces = 0;
    for (int ind = 0; ind < size; ++ind)
    {
        if (text[ind] == ' ')
        {
            ++spaces;
        }
    }

    // if there's at least one space do the replacement.
    if (spaces != 0)
    {
        for(int pos = text.size() - 1; spaces != 0; --size)
        {
            // if there is an space in the text, write the three replacement characters at the end
            // of the string
            if(text[size - 1] == ' ')
            {
                text[pos--]= '0';
                text[pos--]= '2';
                text[pos--]= '%';
                --spaces;
            }
            // if not a space, then simply copy the character to the end
            else
            {
                text[pos--] = text[size - 1];
            }
        }
    }
}

//! Valid urlify example.
TEST(Question_1_3, ValidURLify)
{
    std::string input = "Mr John Smith    ";
    std::string expected = "Mr%20John%20Smith";
    URLify(input, 13);
    ASSERT_TRUE(input == expected);
}

//! Valid urlify example 2.
TEST(Question_1_3, ValidURLify2)
{
    std::string input = "Hello World!  ";
    std::string expected = "Hello%20World!";
    URLify(input, 12);
    ASSERT_TRUE(input == expected);
}

//! Replace multiple spaces on the text.
TEST(Question_1_3, ReplaceSpaces)
{
    std::string input = "a     b          ";
    std::string expected = "a%20%20%20%20%20b";
    URLify(input, 7);
    ASSERT_TRUE(input == expected);
}

//! Text with no spaces (no replacement).
TEST(Question_1_3, NoSpacesReplace)
{
    std::string input = "abcde";
    std::string expected = "abcde";
    URLify(input, 5);
    ASSERT_TRUE(input == expected);
}
