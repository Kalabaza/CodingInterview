#include <gtest/gtest.h>

#include <algorithm>
#include <string>

/**
 * Question 1.3:
 * URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
 * space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note:
 * If implementing in Java, please use a character array so that you can perform this operation in place.)
 */

/**
 * The solution will start from the right of the string and copy characters to there.
 * @param  text The string text that will be checked.
 * @param  size The true size of the input text.
 * @return void
 */
void URLify(std::string &text, int size) {
    // First count the number of spaces in the text, using the true size of it.
    auto spaces = std::count_if(text.begin(), text.begin() + size, [](char c) { return ' ' == c; });

    // If no spaces were found, just return.
    if (0 == spaces) {
        return;
    }

    // Do the replacement from the end of the string until there are no more spaces to replace.
    for (size_t curPos = text.size() - 1; 0 != spaces; --size) {
        // If there is an space in the text, write the three replacement characters at the current position.
        if (text[size - 1] == ' ') {
            text.replace(curPos - 2, 3, std::string("%20"));
            curPos -= 3;
            --spaces;
        }
        // If not a space, then simply copy the character to the current position.
        else {
            text[curPos--] = text[size - 1];
        }
    }
}

//! Test valid urlify example.
TEST(Question_1_3, ValidURLify) {
    std::string input = "Mr John Smith    ";
    std::string expected = "Mr%20John%20Smith";
    URLify(input, 13);
    ASSERT_TRUE(input == expected);
}

//! Test another valid urlify example.
TEST(Question_1_3, ValidURLify2) {
    std::string input = "Hello World!  ";
    std::string expected = "Hello%20World!";
    URLify(input, 12);
    ASSERT_TRUE(input == expected);
}

//! Test to replace multiple continuous spaces on the text.
TEST(Question_1_3, ReplaceSpaces) {
    std::string input = "a     b          ";
    std::string expected = "a%20%20%20%20%20b";
    URLify(input, 7);
    ASSERT_TRUE(input == expected);
}

//! Test with a text with no spaces (no replacement).
TEST(Question_1_3, NoSpacesReplace) {
    std::string input = "abcde";
    std::string expected = "abcde";
    URLify(input, 5);
    ASSERT_TRUE(input == expected);
}
