# Import the unit testing library
import unittest


# Question 1.1:
# Implement an algorithm to determine if a string has all unique characters.
# What if you cannot use additional data structures?

# Check if the input text has repeated characters, assuming that the text is "plain" ASCII.
def has_unique_chars(text):
    # Check if the length of the string is more than 256, meaning that a repeated character
    # was found on the text.
    if len(text) > 256:
        return False

    # Since python does not have arrays, use a list instead of the normal array on other languages,
    # also the list will be initialized to an specific size of 256 with false values.
    char_array = [False] * 256

    # Now loop in the elements of the text getting each character of it.
    for c in text:
        # If the character was already found return false.
        if char_array[ord(c)]:
            return False
        # Mark the character in the list, convert the character to a number using ord().
        char_array[ord(c)] = True

    # No duplicated characters found, return true meaning the text has unique characters.
    return True


# Test cases for the solution, using the intregrated testing capabilities of Python.
class Test(unittest.TestCase):
    # No repeated characters on the text.
    def test_non_repeated_chars(self):
        self.assertTrue(has_unique_chars(text="abcdefg"))

    # Repeated characters on the text.
    def test_repeated_chars(self):
        self.assertFalse(has_unique_chars(text="abcdefgabcdefg"))

    # Empty string test.
    def test_empty_input_string(self):
        self.assertEqual(True, has_unique_chars(text=""))
