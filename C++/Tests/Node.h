template <typename T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node(T data) : data{ data }, next{ nullptr } {}

    // Modifiers for the next pointer
    Node *Next() { return next; }
    void Next(Node* next) { this->next = next; }

    // Modifiers for the data element
    T Data() { return data; }
    void Data(const T &data) { this->data = data; }
};
