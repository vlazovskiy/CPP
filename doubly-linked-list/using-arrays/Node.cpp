// Implementation file for class Node, which will be used by class DoublyLinkedBag

#include "Node.hpp"

// constructors
template<class ItemType>
Node<ItemType>::Node() : prev(-1), next(-1) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType anItem) : item(anItem), prev(-1), next(-1) { }

template<class ItemType>
Node<ItemType>::Node(const ItemType anItem, int prevNodeIndex, int nextNodeIndex) :
                     item(anItem), prev(prevNodeIndex), next(nextNodeIndex) { }

// set methods
template<class ItemType>
void Node<ItemType>::setItem(const ItemType anItem)
{
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setPrev(int prevNodeIndex)
{
    prev = prevNodeIndex;
}

template<class ItemType>
void Node<ItemType>::setNext(int nextNodeIndex)
{
    next = nextNodeIndex;
}

// get methods
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
int Node<ItemType>::getPrev() const
{
    return prev;
}

template<class ItemType>
int Node<ItemType>::getNext() const
{
    return next;
}
