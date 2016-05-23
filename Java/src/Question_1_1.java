
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
	
	public static void main(String[] args) {
		String text = "abcdefg";
		System.out.println(text + "\n" + (hasUniqueChars(text) == true ? "No repeated chars" : "Repeated chars found"));
	}
}
