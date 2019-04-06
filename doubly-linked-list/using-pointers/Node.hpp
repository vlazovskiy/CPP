// Header file for class Node, which will be used by class DoublyLinkedBag

#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
    ItemType item;                    // data item
    Node<ItemType>* prev;             // pointer to previous node
    Node<ItemType>* next;             // pointer to next node
public:
    // constructors
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* prevNodePtr, Node<ItemType>* nextNodePtr);
    // set methods
    void setItem(const ItemType& anItem);
    void setPrev(Node<ItemType>* prevNodePtr);
    void setNext(Node<ItemType>* nextNodePtr);
    // get methods
    ItemType getItem() const;
    Node<ItemType>* getPrev() const;
    Node<ItemType>* getNext() const;
};

#endif
