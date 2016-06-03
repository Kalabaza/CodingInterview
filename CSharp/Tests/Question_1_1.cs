using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Tests
{
    [TestClass]
    public class Question_1_1
    {
        // Question 1.1:
        // Implement an algorithm to determine if a string has all unique characters.
        // What if you cannot use additional data structures?

        // The solution will assume that only ASCII characters are going to be received.
        public bool HasUniqueChars(string text)
        {
            // If more than 256 characters in the string, then at least one is repeated.
            if (text.Length > 256)
                return false;

            // Array of booleans to check is a character is duplicated.
            var charArray = new bool[256];

            // Get each character from the string
            foreach (var c in text)
            {
                // If the character was already found, return false.
                if (charArray[c])
                    return false;
                // Mark the position on the array.
                charArray[c] = true;
            }

            // No repeated characters found, return true.
            return true;
        }

        // Test methods to ensure the solution was correct, will be using the unit testing
        // capabilities of the C# language.

        // No repeated characters in the text.
        [TestMethod]
        public void NonRepeatedChars()
        {
            const string text = "abcdefg";
            Assert.IsTrue(HasUniqueChars(text));
        }

        // Repeated characters in the text
        [TestMethod]
        public void RepeatedChars()
        {
            const string text = "abcdefgabcdefg";
            Assert.IsFalse(HasUniqueChars(text));
        }

        [TestMethod]
        public void EmptyInputString()
        {
            const string text = "";
            Assert.IsTrue(HasUniqueChars(text));
        }
    }
}
