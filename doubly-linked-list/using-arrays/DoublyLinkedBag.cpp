// Implementation file for class DoublyLinkedBag

#include "DoublyLinkedBag.hpp"

/* default constructor: creates an array which will be used for linking;
   the first Node will have it's 'Prev' pointing at -1 index, and its last
   element point to -1 index */
template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : head(0), free(0), itemCount(0)
{
    for (int i = 0; i < DEFAULT_CAPACITY; i++)
    {
        linkArray[i].setPrev(i - 1);
        linkArray[i].setNext(i + 1);
    }
    linkArray[DEFAULT_CAPACITY - 1].setNext(-1);
}

/* copy constructor: copies the underlying array structure exactly as it
   appears in the original object (item order is preserved) */
template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag) :
                                           head(aBag.head), free(aBag.free), itemCount(aBag.itemCount)
{
    for (int i = 0; i < DEFAULT_CAPACITY; i++)
    {
        linkArray[i] = aBag.linkArray[i];
    }
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getIndexOf(const ItemType target) const
{
    bool found = false;
    int curIndex = head;
    while (!found && (curIndex != -1))
    {
        if (target == linkArray[curIndex].getItem())
            found = true;
        else
            curIndex = linkArray[curIndex].getNext();
    }
    return curIndex;
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
bool DoublyLinkedBag<ItemType>::contains(const ItemType anEntry) const
{
    int curIndex = head;
    int counter = 0;
    bool contains = false;
    while ((curIndex != -1) && (counter < itemCount))
    {
        if (anEntry == linkArray[curIndex].getItem())
        {
            contains = true;
            curIndex = -1;
        }
        curIndex = linkArray[curIndex].getNext();
        counter++;
    }
    return contains;
}

template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType anEntry) const
{
    int frequency = 0;
    int counter = 0;
    int curIndex = head;
    while ((curIndex != -1) && (counter < itemCount))
    {
        if (anEntry == linkArray[curIndex].getItem())
            frequency++;
        counter++;
        curIndex = linkArray[curIndex].getNext();
    }
    return frequency;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType newEntry)
{
    bool canAdd;
    if (isEmpty()) // First element is a special case: its previous and next indices are -1
    {
        free = linkArray[head].getNext();
        linkArray[head] = Node<ItemType>(newEntry, -1, -1);
        itemCount++;
        canAdd = true;
    }
    else if (itemCount <= DEFAULT_CAPACITY)
    {
        // new node's prev member points to current head
        Node<ItemType> newNode = Node<ItemType>(newEntry, -1, head);
        // current index of the free element in the array
        int curIndex = free;
        // update linking indices for the former first element and add the new node
        free = linkArray[curIndex].getNext();
        linkArray[head].setPrev(curIndex);
        head = curIndex;
        linkArray[curIndex] = newNode;
        itemCount++;
        canAdd = true;
    }
    else // case when itemCount == DEFAULT_CAPACITY
    {
        canAdd = false;
    }
    return canAdd;
}

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType anEntry)
{
    int entryIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (entryIndex != -1);
    if (canRemoveItem)
    {
        /* the idea here is remove a node and chain together the nodes
           before and after this node, while also updating the free index
           and making sure this empty node also points to the index of the
           next element in the free list (after the free node) */
        int prevIndex = linkArray[entryIndex].getPrev();
        int nextIndex = linkArray[entryIndex].getNext();
        linkArray[prevIndex].setNext(linkArray[entryIndex].getNext());
        linkArray[nextIndex].setPrev(linkArray[entryIndex].getPrev());
        linkArray[entryIndex].setNext(free);
        free = entryIndex;
        itemCount--;
    }
    return canRemoveItem;
}

/* this methods uses remove method to clear the linked list
   since we are not using pointers, we don't have to deallocate a
   memory manually and can let the remove method do the work */
template<class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
    int curIndex = head;
    while (itemCount != 0)
    {
        remove(linkArray[curIndex].getItem());
    }
}

template<class ItemType>
std::vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    int curIndex = head;
    int counter = 0;
    while ((curIndex != -1) && (counter < itemCount))
    {
        bagContents.push_back(linkArray[curIndex].getItem());
        curIndex = linkArray[curIndex].getNext();
        counter++;
    }
    return bagContents;
}

