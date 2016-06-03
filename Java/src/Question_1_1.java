import static org.junit.Assert.*;
import org.junit.Test;

// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

// Assuming that ASCII characters are going to be received in the input string.
public class Question_1_1 {
	static boolean hasUniqueChars(String text) {
		// If more than 256 chars in the input string one of them is repeated.
		if (text.length() > 256)
			return false;

		// Array of booleans to detect duplicates in the text.
		boolean[] charArray = new boolean[256];

		// Get each one of the chars in the text, in order to do this the string
		// has to be converted into a char array to get individual characters.
		for (char c : text.toCharArray()) {
			// If the char was already found, return false.
			if (charArray[c])
				return false;
			// Mark the char as found in the array.
			charArray[c] = true;
		}

		// If no repetitions found, return true.
		return true;
	}

	// Test cases to check the solution of the question, these will use JUnit
	
	// Non repeated characters in the text.
	@Test
	public void NonRepeatedChars() {
		String text = "abcdefg";
		assertTrue(hasUniqueChars(text));
	}

	// Repeated characters in the text.
	@Test
	public void RepeatedChars() {
		String text = "abcdefgabcdefg";
		assertFalse(hasUniqueChars(text));
	}

	// Empty text.
	@Test
	public void EmptyInputString() {
		String text = "";
		assertEquals(true, hasUniqueChars(text));
	}
}
