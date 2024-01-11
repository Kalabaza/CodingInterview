#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack
{
private:
    Node<T> *head;
    size_t size;

public:
    Stack() : head{ nullptr }, size{ 0 } {}
    Stack(std::initializer_list<T> list) : head{ nullptr }, size{ 0 }
    {
        for (auto &e : list)
            Push(e);
    }
    ~Stack()
    {
        while (head != nullptr)
        {
            auto next = head->Next();
            delete head;
            head = next;
        }
    }

    void Push(T data)
    {
        if (head == nullptr)
            head = new Node<T>(data);
        else
        {
            auto tmp = new Node<T>(data);
            tmp->Next(head);
            head = tmp;
        }
        ++size;
    }

    void Pop()
    {
        if (head != nullptr)
        {
            auto tmp = head;
            head = head->Next();
            delete tmp;
            --size;
        }
    }

    T Top() const
    {
        if (head != nullptr)
            return head->Data();
        // If this point is reached, an exception must be thrown.
        throw std::logic_error("Head equal to nullptr, there are no elements in the Stack.");
    }

    size_t Size()
    {
        return size;
    }

    bool Empty()
    {
        return head == nullptr;
    }
};
