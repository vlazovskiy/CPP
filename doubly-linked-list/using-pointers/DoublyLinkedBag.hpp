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
    Node<ItemType>* headPtr;
    int itemCount;
    Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
    DoublyLinkedBag();                                      // default constructor
    DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag); // copy constructor
    bool add(const ItemType& newEntry);
    std::vector<ItemType> toVector() const;
    bool isEmpty() const;
    int getCurrentSize() const;
    int getFrequencyOf(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;
    bool remove(const ItemType& anEntry);
    void clear();
    virtual ~DoublyLinkedBag();
};

#endif
