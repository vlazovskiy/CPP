// Header file for class DoublyLinkedBag which will be used in main()

#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG

#include "Node.hpp"
#include "Node.cpp" // the .cpp file is included to avoid linker error due to template class
#include <vector>

template<class ItemType>
class DoublyLinkedBag
{
private:
    static const int DEFAULT_CAPACITY = 5;
    Node<ItemType> linkArray [DEFAULT_CAPACITY];
    int head;
    int free;
    int itemCount;
    int getIndexOf(const ItemType target) const;
public:
    DoublyLinkedBag();                                      // default constructor
    DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag); // copy constructor
    bool isEmpty() const;
    int getCurrentSize() const;
    bool contains(const ItemType anEntry) const;
    int getFrequencyOf(const ItemType anEntry) const;
    bool add(const ItemType newEntry);
    bool remove(const ItemType anEntry);
    void clear();
    std::vector<ItemType> toVector() const;
};

#endif
