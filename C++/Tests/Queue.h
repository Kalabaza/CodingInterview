#include <stdexcept>
#include "Node.h"

template <typename T>
class Queue
{
private:
    Node<T> *front, *back;
    size_t size;

public:
    Queue() : front{ nullptr }, back{ nullptr }, size{ 0 } {}
    ~Queue()
    {
        while(front != nullptr)
        {
            auto next = front->Next();
            delete front;
            front = next;
        }
    }

    void Push(T data)
    {
        if (back == nullptr)
            front = back = new Node<T>(data);
        else
        {
            auto tmp = new Node<T>(data);
            back->Next(tmp);
            back = tmp;
        }
        ++size;
    }

    void Pop()
    {
        if (front != nullptr)
        {
            auto tmp = front;
            front = front->Next();
            delete tmp;
            --size;
            if (front == nullptr)
                back = front;
        }
    }

    T Front()
    {
        if (front != nullptr)
            return front->Data();
        // If this point is reached, an exception must be thrown.
        throw std::logic_error("Front equal to nullptr, there are no elements in the Queue.");
    }

    T Back()
    {
        if (back != nullptr)
            return back->Data();
        // If this point is reached, an exception must be thrown.
        throw std::logic_error("Back equal to nullptr, there are no elements in the Queue.");
    }

    size_t Size()
    {
        return size;
    }

    bool Empty()
    {
        return front == nullptr;
    }
};
