// Implementation file for class DoublyLinkedBag

#include "DoublyLinkedBag.hpp"
#include <iostream>
using namespace std;

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;
    if (origChainPtr == nullptr)
        headPtr = nullptr;
    else
    {
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        headPtr->setPrev(nullptr);
        Node<ItemType>* newChainPtr = headPtr;
        while (origChainPtr->getNext() != nullptr)
        {
            origChainPtr = origChainPtr->getNext();
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newNodePtr->setPrev(newChainPtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
    clear();
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
    bool firstNode = (headPtr == nullptr);
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr);
    if (!firstNode)
        headPtr->setPrev(newNodePtr);
    headPtr = newNodePtr;
    itemCount++;
    return true;
}

template<class ItemType>
std::vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    return bagContents;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
            frequency++;
        counter ++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    while (!found && (curPtr != nullptr))
    {
        if (target == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        entryNodePtr->setItem(headPtr->getItem());
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setPrev(nullptr);
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
    }
    return canRemoveItem;
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
    while (headPtr != nullptr)
    {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setPrev(nullptr);
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
    }
    headPtr = nullptr;
    itemCount = 0;
}
