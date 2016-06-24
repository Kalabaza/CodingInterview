#include <vector>
#include "Node.h"

template <typename T>
class LinkedList
{
private:
    // When a template class is used, the argument have to be specified when a variable is created.
    Node<T> *root;
    // Add a node to signal the end of the linked list in order to add nodes at the end
    Node<T> *end;

public:
    LinkedList() : root{ nullptr } {}

    ~LinkedList() 
    {
        while (root != nullptr)
        {
            auto next = root->Next();
            delete root;
            root = next;
        }
    }

    // Modifiers for the root pointer
    Node<T> *Root() { return root; }
    void Root(Node<T> *root) { this->root = root; }

    // Modifiers for the end pointer
    Node<T> *End() { return end; }
    void End(Node<T> *end) { this->end = end; }

    void AddNodeAtStart(const T &data)
    {
        // Check if the linked list is empty or not.
        if (root == nullptr)
            end = root = new Node<T>(data);
        else
        {
            // Add the new element to the beginning of the linked list.
            auto tmp = new Node<T>(data);
            tmp->Next(root);
            root = tmp;
        }
    }

    void AddNodeAtEnd(const T &data)
    {
        if (end == nullptr)
            end = root = new Node<T>(data);
        else
        {
            // Add the new element to the end of the linked list.
            auto tmp = new Node<T>(data);
            end->Next(tmp);
            end = tmp;
        }
    }

    bool DeleteNode(T data)
    {
        // At least the linked list should have one element to remove.
        if (root == nullptr)
            return false;

        // Check if the root is the node that will be removed.
        if (root->data == data)
        {
            auto tmp = root;
            root = root->next;
            delete tmp;
            if (root == nullptr)
                end = root;
            return true;
        }
        else
        {
            auto tmp = root;
            while (tmp->next != nullptr)
            {
                if (tmp->next->data == data)
                {
                    auto tmp2 = tmp->next;
                    tmp->next = tmp2->next;
                    delete tmp2;
                    return true;
                }
                tmp = tmp->next;
            }
        }

        // Reaching this point means that no element was removed from the linked list.
        return false;
    }

    std::vector<T> GetValues()
    {
        std::vector<T> result;
        auto tmp = root;
        while(tmp != nullptr)
        {
            result.push_back(tmp->Data());
            tmp = tmp->Next();
        }
        return result;
    }

    Node<T> *GetNode(T data)
    {
        auto tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->Data() == data)
                return tmp;
            tmp = tmp->Next();
        }
        return nullptr;
    }

    // Question 2.1
    void RemoveDuplicates();

    // Question 2.2
    Node<T> *FindKthNode(int);

    // Question 2.3
    void DeleteNode(Node<T>*);

    // Question 2.4
    void PartitionList(T);

    // Question 2.6
    Node<T> *GetLoopStart();

    // Question 2.7
    bool IsPalindrome();
};
