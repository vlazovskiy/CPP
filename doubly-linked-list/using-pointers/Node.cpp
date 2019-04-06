// Implementation file for class Node, which will be used by class DoublyLinkedBag

#include "Node.hpp"

// constructors
template<class ItemType>
Node<ItemType>::Node() : prev(nullptr), next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), prev(nullptr), next(nullptr) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* prevNodePtr, Node<ItemType>* nextNodePtr) : item(anItem), prev(prevNodePtr), next(nextNodePtr) { }

// set methods
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

// get methods
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const
{
    return prev;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}
