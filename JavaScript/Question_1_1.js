// Question 1.1:
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

// Method to check is a string has repeated characters, assuming that the input text is ASCII.
function hasUniqueChars(text)
{
    // Check if the text has more than 256 characters, meaning that at least one is repeated.
    if (text.length > 256) {
        return false;
    }
    
    // Create an array of boolean values of 256 elements and put initialize them with zeros.
    var charArray = Array.apply(null, Array(256)).map(Boolean);
    
    // Iterate in the elements of the text, will get the index of the text instead of the char.
    for (i in text) {
        // If the character was already found return false.
        if(charArray[text[i]]) {
            return false;
        }
        // Mark the character in the array.
        charArray[text[i]] = true;
    }
    
    // If no repeated characters were found, return true to mark that the text has unique chars.
    return true;
}

// Using the QUnit framework to do the testing of the function.

// Create a module to put the tests togheter on the result page.
QUnit.module( "Question_1_1" );

// Test for non repeated characters in the text.
QUnit.test("NonRepeatedChars", function(assert) {
    var text = "abcdefg";
    assert.ok(hasUniqueChars(text));
});

// Test for repeated characters in the text.
QUnit.test("RepeatedChars", function(assert) {
    var text = "abcdefgabcdefg";
    assert.ok(!hasUniqueChars(text), false, "Success");
});

// Empty text test.
QUnit.test("EmptyInputString", function(assert) {
    var text = "";
    assert.ok(hasUniqueChars(text));
});