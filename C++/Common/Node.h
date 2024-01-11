// Template class to represent a Node that could be used either on a Linked list or a Queue.
template <typename T>
class Node
{
private:
    // Element that will be saved in the Node.
    T data;
    // Pointer to another element.
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
