using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Tests
{
    // Question 1.2:
    // Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

    [TestClass]
    public class Question_1_2
    {
        // Question 1.2:
        // Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

        // Helper method to swap two characters in place.
        public void SwapChars(ref string text, int a, int b)
        {
            var c = text[a];
            // Change the characters using the extension method ReplaceAtIndex since the indexer of
            // the string cannot be received as reference into this method.
            text = text.ReplaceAtIndex(a, text[b]);
            text = text.ReplaceAtIndex(b, c);
        }

        // The method will receive a string and will reverse it on place.
        public void ReverseString(ref string text)
        {
            // If there are no characters in the string, return.
            if (text.Length == 0)
                return;

            var size = text.Length;
            for (var i = 0; i < size / 2; ++i)
            {
                // Swap the two characters, in this case the reference will be send.
                SwapChars(ref text, i, size - 1 - i);
            }
        }

        // Reverse a string with even number of characters.
        [TestMethod]
        public void ReverseStringEvenLength()
        {
            var text = "abcd";
            ReverseString(ref text);
            Assert.AreEqual("dcba", text);
        }

        // Reverse a string with odd number of characters.
        [TestMethod]
        public void ReverseStringOddLength()
        {
            var text = "abcde";
            ReverseString(ref text);
            Assert.AreEqual("edcba", text);
        }

        // Try to reverse an empty string.
        [TestMethod]
        public void ReverseEmptyString()
        {
            var text = "";
            ReverseString(ref text);
            Assert.AreEqual("", text);
        }
    }
}
