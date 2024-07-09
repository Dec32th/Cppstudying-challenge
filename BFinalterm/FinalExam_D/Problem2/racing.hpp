#include <iostream>
#include <string>
#include<ctime>
using namespace std;


int hashFunction_Cat(int ID)
{
    return ID % 40;
}

int hashFunction_Dog(int ID)
{
    return (ID%20+30)%40;
}

int hashFunction(int ID)
{
    if (ID < 2000)
        return ID % 40;
    else
        return (ID % 20 + 30) % 40;
}

template<class ItemType>
class HashTable
{
private:
    ItemType values[40];
public:
    void Hash(key)
    {
       
    };
};


class Cat
{
    Cat(int randseed) { ID = randseed;};
    ~Cat() {};
private:
    int ID;
    int speed;
};

class Dog
{
    Dog(int randseed) { ID = randseed;};
    ~Dog() {};
private:
    int ID;
    int speed;
};