#include <iostream>
#include <string>
#include <vector>
#include "Node.hpp"
#include "DoublyLinkedBag.hpp"
#include "DoublyLinkedBag.cpp" // the .cpp file is included to avoid linker error due to template class
using namespace std;

// Helper function to display the vector with bag content
template<class ItemType>
void displayVector(vector<ItemType> &vect);

int main() {
    
    std::vector<string> bagItems;
    DoublyLinkedBag<string> myBag;
    
    bagItems = myBag.toVector();
    cout << "My bag now: ";
    displayVector(bagItems);
    cout << endl << "Bag empty? — " << myBag.isEmpty() << endl;
    
    string myArray [5] = {"A", "B", "C", "C", "D"};
    for (int i = 0; i < 5; i++)
    {
        myBag.add(myArray[i]);
        cout << "Adding '" << myArray[i] << "' — ";
        bagItems = myBag.toVector();
        cout << "My bag now: ";
        displayVector(bagItems);
        cout << endl;
    }
    
    DoublyLinkedBag<string> myBagCopy(myBag);
    bagItems = myBagCopy.toVector();
    cout << "My bag copy: ";
    displayVector(bagItems);
    cout << endl;
    
    cout << "Removing 'B' — ";
    myBag.remove("B");
    bagItems = myBag.toVector();
    cout << "My bag now: ";
    displayVector(bagItems);
    cout << endl;
    
    cout << "Adding 'B' back — ";
    myBag.add("B");
    bagItems = myBag.toVector();
    cout << "My bag now: ";
    displayVector(bagItems);
    cout << endl;
    
    cout << "Adding 'F' to full bag — ";
    myBag.add("F");
    bagItems = myBag.toVector();
    cout << "My bag now: ";
    displayVector(bagItems);
    cout << endl;
    
    cout << "My bag size: " << myBag.getCurrentSize() << endl;
    cout << "My bag contains 'A'? – " << myBag.contains("A") << endl;
    cout << "My bag contains 'F'? — " << myBag.contains("F") << endl;
    cout << "Frequency of 'B': " << myBag.getFrequencyOf("B") << endl;
    cout << "Frequency of 'C': " << myBag.getFrequencyOf("C") << endl;
    
    cout << "Clearing my bag! – ";
    myBag.clear();
    bagItems = myBag.toVector();
    displayVector(bagItems);
    cout << "My bag now: ";
    cout << endl << "Bag empty? — " << myBag.isEmpty() << endl;
    
    bagItems = myBagCopy.toVector();
    cout << "Check bag copy: ";
    displayVector(bagItems);
    
    cout << endl << endl;
    return 0;
}

/* main() output:
 
 My bag now:
 Bag empty? — 1
 Adding 'A' — My bag now: A
 Adding 'B' — My bag now: B A
 Adding 'C' — My bag now: C B A
 Adding 'C' — My bag now: C C B A
 Adding 'D' — My bag now: D C C B A
 My bag copy: D C C B A
 Removing 'B' — My bag now: D C C A
 Adding 'B' back — My bag now: B D C C A
 Adding 'F' to full bag — My bag now: B D C C A
 My bag size: 5
 My bag contains 'A'? – 1
 My bag contains 'F'? — 0
 Frequency of 'B': 1
 Frequency of 'C': 2
 Clearing my bag! – My bag now:
 Bag empty? — 1
 Check bag copy: D C C B A
 
 */

template<class ItemType>
void displayVector(vector<ItemType> &vect)
{
    unsigned long numberOfEntries = vect.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << vect[i] << " ";
    }
}
