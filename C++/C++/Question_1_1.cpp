#include <iostream>
#include <string>

using namespace std;

// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?

bool hasUniqueChars(const string &text)
{
    // Considering that only ASCII characters are going to be received on the string
    // an array of 256 positions is enough to tell if there are any repeated
    // chars in the input string.
    bool charArray[256] = {};

    // If more than 256 are received on the input string it means that at least one
    // character is repeated.
    if (text.size() >= 256)
        return false;

    // Take each letter of the input text and mark the position on the array for that
    // specific letter, if the position was already marked it means that a duplicated
    // character was found.
    for (auto &c : text)
    {
        // Return false to indicate that a character was repeated in the text.
        if (charArray[c] == true)
            return false;
        // Mark the position on the array.
        charArray[c] = true;
    }

    // If there was not a repeated character, return true.
    return true;
}

int main(int argc, char** argv)
{
    string text{ "abcdefg" };
    cout << text << endl << (hasUniqueChars(text) == true ? "No repeated chars" : "Repeated chars found") << endl;
    return 0;
}
