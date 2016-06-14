using System.Text;

namespace Tests
{
    public static class ExtensionMethods
    {
        // Helper method to replace an specific character in a string, since strings are
        // immutable in C#, a new string has to be received when this extension method is used.
        public static string ReplaceAtIndex(this string orgText, int i, char c)
        {
            var newText = new StringBuilder(orgText) { [i] = c };
            return newText.ToString();
        }
    }
}
