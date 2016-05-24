import static org.junit.Assert.*;
import org.junit.Test;

//Question 1.1:
//Implement an algorithm to determine if a string has all unique characters. What
//if you cannot use additional data structures?

public class Question_1_1 {

	static boolean hasUniqueChars(String text) {
		boolean[] charArray = new boolean[256];
		
		if (text.length() >= 256)
			return false;
		
		// Loop in each one of the chars of the string, in order to do this
		// the string has to be converted into a char array
		for (char c : text.toCharArray()) {
			if (charArray[c] == true)
				return false;
			charArray[c] = true;
		}
		
		return true;
	}
	
	@Test
	public void NonRepeatedChars() {
		String text = "abcdefg";
		assertTrue(hasUniqueChars(text));
	}
	
	@Test
	public void RepeatedChars() {
		String text = "abcdefgabcdefg";
		assertFalse(hasUniqueChars(text));
	}
	
	@Test
	public void EmptyInputString() {
		String text = "";
		assertTrue(hasUniqueChars(text));
	}
}
