#include <gtest/gtest.h>
#include <tuple>
#include "Queue.h"

// 3.7 An animal shelter holds only dogs and cats, and operates on a strictly "first in,
// first out" basis. People must adopt either the "oldest" (based on arrival time) of
// all animals at the shelter, or they can select whether they would prefer a dog or
// a cat(and will receive the oldest animal of that type).They cannot select which
// specific animal they would like. Create the data structures to maintain this system
// and implement operations such as enqueue, dequeueAny, dequeueDog and
// dequeueCat.You may use the built - in LinkedList data structure.

template<typename T>
class AnimalShelter
{
private:
    Queue<std::tuple<T, unsigned>> dogs, cats;
    unsigned order;
public:
    AnimalShelter() : order{ 0 } {}

    void AddDog(const T &breed)
    {
        dogs.Push(std::make_tuple(breed, order++));
    }

    void AddCat(const T &breed)
    {
        cats.Push(std::make_tuple(breed, order++));
    }

    std::string SelectDog()
    {
        std::string breed;
        if (!dogs.Empty())
        {
            breed = std::get<0>(dogs.Front());
            dogs.Pop();
        }
        return breed;
    }

    std::string SelectCat()
    {
        std::string breed;
        if (!cats.Empty())
        {
            breed = std::get<0>(cats.Front());
            cats.Pop();
        }
        return breed;
    }

    std::string SelectAny()
    {
        std::string breed;
        // If there are cats and dogs, take the oldest of them.
        if (!dogs.Empty() && !cats.Empty())
        {
            if (std::get<1>(dogs.Front()) < std::get<1>(cats.Front()))
            {
                breed = std::get<0>(dogs.Front());
                dogs.Pop();
            }
            else
            {
                breed = std::get<0>(cats.Front());
                cats.Pop();
            }
        }
        // If there are no dogs, take a cat.
        else if (dogs.Empty())
        {
            breed = std::get<0>(cats.Front());
            cats.Pop();
        }
        // If there are no cats, take a dog.
        else
        {
            breed = std::get<0>(dogs.Front());
            dogs.Pop();
        }
        return breed;
    }
};

TEST(Question_3_7, AnimalShelterWithQueues)
{
    AnimalShelter<std::string> shelter;
    shelter.AddDog("Bulldog");
    shelter.AddCat("Siamese");
    shelter.AddDog("Beagle");
    shelter.AddCat("Persian");
    shelter.AddDog("Dachshund");
    shelter.AddCat("Siberian");
    ASSERT_EQ("Bulldog", shelter.SelectAny());
    ASSERT_EQ("Beagle", shelter.SelectDog());
    ASSERT_EQ("Siamese", shelter.SelectCat());
    ASSERT_EQ("Persian", shelter.SelectCat());
    ASSERT_EQ("Dachshund", shelter.SelectAny());
    ASSERT_EQ("Siberian", shelter.SelectAny());
}
