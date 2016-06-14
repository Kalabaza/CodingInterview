package tests

import "testing"

// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

// Function to check if a string has repeated characters, will be assuming that the input
// text is ASCII.
func HasUniqueChars(text string) bool {
	// Check if the text has more than 256 runes, meaning that at least one of them is
	// repeated on the text.
	if len([]rune(text)) > 256 {
		return false
	}

	// Array of booleans to check if a character is repeated.
	var charArray [256]bool
	// Using a range for but ignoring the index value since is not used on the code.
	for _, r := range text {
		// If the value was already found, return false.
		if charArray[r] {
			return false
		}
		// Mark the character on the array.
		charArray[r] = true
	}

	// No duplicated characters found, return true to signal that the text has all
	// unique characters.
	return true
}

// Test cases using the available functionality on the Go language.

// Non repeated characters in text.
func TestNonRepeatedChars(t *testing.T) {
	var text string
	text = "abcdefg"
	if result := HasUniqueChars(text); result == false {
		t.FailNow()
	}
}

// Repeated characters in the text.
func TestRepeatedChars(t *testing.T) {
	var text = "abcdefgabcdefg"
	if result := HasUniqueChars(text); result == true {
		t.FailNow()
	}
}

// Empty string test.
func TestEmptyInputString(t *testing.T) {
	text := ""
	if result := HasUniqueChars(text); result == false {
		t.FailNow()
	}
}
