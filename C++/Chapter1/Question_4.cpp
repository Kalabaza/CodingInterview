#include <gtest/gtest.h>

#include <algorithm>
#include <map>
#include <string>

/**
 * Question 1.4:
 * Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A
 * palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
 */

/**
 * The solution will start from the right of the string and copy characters to there.
 * @param  text The string text that will be checked.
 * @return      True if the string is a permutation of a palindrome.
 */
bool PalindromePermutation(std::string &text) {
    /// Change all the characters to lower case
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    /// Remove any spaces from the text (is this allowed?)
    text.erase(std::remove_if(text.begin(), text.end(), ::isspace), text.end());

    /// Add the characters to a map, to count the repetitions
    std::map<char, int> rep;
    for (auto &c : text) {
        ++rep[c];
    }

    /// Now, if the number of characters is odd
    if ((rep.size() % 2) == 1) {
        /// All the characters must have an even number of letters
        for (const auto &e : rep) {
            if (e.second % 2 != 0) {
                return false;
            }
        }
    } else {
        /// Otherwise, only one character can have and odd number of letters
        bool odd = false;
        for (const auto &e : rep) {
            if (e.second % 2 == 1) {
                if (odd) {
                    return false;
                }
                odd = true;
            }
        }
    }

    return true;
}

/// A valid palindrome permutation
TEST(Question_4, ValidPalindromePermutation) {
    std::string text = "Tact Coa";
    ASSERT_TRUE(PalindromePermutation(text));
}

/// Another valid palindrome permutation
TEST(Question_4, ValidPalindromePermutation2) {
    std::string text = "Anita lava la tina";
    ASSERT_TRUE(PalindromePermutation(text));
}
