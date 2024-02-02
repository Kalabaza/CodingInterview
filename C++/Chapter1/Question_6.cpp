#include <gtest/gtest.h>

#include <string>

/**
 * Question 1.5:
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than the original
 * string, your method should return the original string.
 */

std::string CompressText(const std::string &text) {
    /// The text must have at least three characters in order to produce a compressed string.
    if (text.length() <= 2) return text;

    std::string result;
    auto c = text[0];
    int n = 1;

    for (size_t i = 1; i < text.length(); ++i) {
        if (c == text[i]) {
            ++n;
        } else {
            result += c + std::to_string(n);
            c = text[i];
            n = 1;
        }
    }
    /// Add the last sequence to the compressed string.
    result += c + std::to_string(n);

    /// Check if the length of the resulting string is less that the original text.
    if (result.length() >= text.length()) {
        return text;
    }

    return result;
}

/// Valid string will be compressed.
TEST(Question_1_5, ValidCompressText) {
    std::string text{"aabcccccaaa"};
    text = CompressText(text);
    ASSERT_EQ("a2b1c5a3", text);
}

/// Valid text with spaces.
TEST(Question_1_5, ValidCompressTextWIthSpaces) {
    std::string text{"a  bbbcccc"};
    text = CompressText(text);
    ASSERT_EQ("a1 2b3c4", text);
}

/// Text of only one character.
TEST(Question_1_5, SingleCharacterText) {
    std::string text{"a"};
    text = CompressText(text);
    ASSERT_EQ("a", text);
}

/// Only two characters, cannot be compressed.
TEST(Question_1_5, InvalidTextLength) {
    std::string text{"ab"};
    text = CompressText(text);
    ASSERT_EQ("ab", text);
}

/// Compressed text larger than the original text
TEST(Question_1_5, InvalidCompressedText) {
    std::string text{"abc"};
    text = CompressText(text);
    ASSERT_EQ("abc", text);
}
