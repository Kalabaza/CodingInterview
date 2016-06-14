inline void SwapChars(char *a, char *b)
{
    auto c = *a;
    *a = *b;
    *b = c;
}


// Auxiliary method to swap two characters to avoid using std::swap().
inline void SwapChars(char &a, char &b)
{
    auto c = a;
    a = b;
    b = c;
}