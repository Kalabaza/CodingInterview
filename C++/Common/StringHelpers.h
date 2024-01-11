
// Method to swap two characters using the char pointers to them.
inline void SwapChars(char *a, char *b)
{
    auto c = *a;
    *a = *b;
    *b = c;
}

// Method to swap two characters received by reference to avoid using std::swap().
inline void SwapChars(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
}
