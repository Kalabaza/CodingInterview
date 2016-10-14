#include <string>
#include <gtest/gtest.h>

//? Question 1.4:
// Write a method to replace all spaces in a string with '%20'. You may assume that the
// string has sufficient space at the end of the string to hold the additional characters,
// and that you are given the "true" length of the string. (Note: if implementing in Java,
// please use a character array so that you can perform this operation in place.)

// The replacement of the characters will be done backwards since there is enough space in the
// array to hold the data without using a new array.
void ReplaceSpaces(char *text, int size)
{
    // First count how many spaces are on the text.
    int spaces = 0;
    for (int i = 0; i < size; ++i)
        if (text[i] == ' ')
            ++spaces;

    // If there's at least one space do the replacement.
    if (spaces != 0)
    {
        // Calculate the total size of the string with the replaced characters.
        int totalSize = size + spaces * 2;
        // Put the new end of string character.
        text[totalSize] = '\0';

        for (int i = size - 1; i >= 0 && spaces != 0; --i)
        {
            // If a space is found on the text, change it for the characters %20.
            if (text[i] == ' ')
            {
                text[--totalSize] = '0';
                text[--totalSize] = '2';
                text[--totalSize] = '%';
                // Just do the process as many times as characters there are in the text, when
                // all the spaces are changed, the rest of the text will not be changed.
                --spaces;
            }
            // Otherwise, just copy the character into the new location.
            else
            {
                text[--totalSize] = text[i];
            }
        }
    }
}

//! Replace only one space on the text.
TEST(Question_1_4, ReplaceSpace)
{
    char *text = new char[14]{ "Sample text" };
    ReplaceSpaces(text, strlen(text));
    ASSERT_EQ("Sample%20text", std::string(text));
    delete[] text;
}

//! Replace multiple spaces on the text.
TEST(Question_1_4, ReplaceSpaces)
{
    char *text = new char[18]{ "a     b" };
    ReplaceSpaces(text, strlen(text));
    ASSERT_EQ("a%20%20%20%20%20b", std::string(text));
    delete[] text;
}

//! Text with no spaces (no replacement).
TEST(Question_1_4, NoSpacesReplace)
{
    char *text = new char[18]{ "abcde" };
    ReplaceSpaces(text, strlen(text));
    ASSERT_EQ("abcde", std::string(text));
    delete[] text;
}
