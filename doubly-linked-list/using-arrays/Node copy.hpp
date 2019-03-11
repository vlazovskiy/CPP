// Header file for class Node, which will be used by class DoublyLinkedBag

#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
    ItemType item;        // A data item
    int prev;             // Index of previous element
    int next;             // Index of next element
public:
    // constructors
    Node();
    Node(const ItemType anItem);
    Node(const ItemType anItem, int prev, int next);
    // set methods
    void setItem(const ItemType anItem);
    void setPrev(int prevNodeIndex);
    void setNext(int nextNodeIndex);
    // get methods
    ItemType getItem() const;
    int getPrev() const;
    int getNext() const;
};

#endif
