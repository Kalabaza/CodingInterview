// Method to swap two characters using the pointers to them.
inline void SwapChars(char *a, char *b)
{
    auto c = *a;
    *a = *b;
    *b = c;
}


// Method to swap two characters to avoid using std::swap().
inline void SwapChars(char &a, char &b)
{
    auto c = a;
    a = b;
    b = c;
}