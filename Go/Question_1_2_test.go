package tests

import "testing"

// Question 1.2:
// Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

func SwapChars(orgText *string, a int, b int) {
	c := (*orgText)[a]
	// Since strings are immutable objects on Go, create a new string with the replacements
	*orgText = (*orgText)[:a] + string((*orgText)[b]) + (*orgText)[a+1:]
	*orgText = (*orgText)[:b] + string(c) + (*orgText)[b+1:]
}

func ReverseString(text *string) {
	if len([]rune(*text)) == 0 {
		return
	}

	size := len([]rune(*text))
	for i := 0; i < size/2; i++ {
		SwapChars(text, i, size-1-i)
	}
}

func TestReverseStringEvenLength(t *testing.T) {
	text := "abcd"
	if ReverseString(&text); "dcba" != text {
		t.FailNow()
	}
}

func TestReverseStringOddLength(t *testing.T) {
	text := "abcde"
	if ReverseString(&text); "edcba" != text {
		t.FailNow()
	}
}

func TestReverseEmptyString(t *testing.T) {
	text := ""
	if ReverseString(&text); "" != text {
		t.FailNow()
	}
}
