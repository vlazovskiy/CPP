#include <iostream>
using namespace std;

// Function declarations
int kSmall(int k, int anArray[], int first, int last);
int partition(int anArray[], int first, int last);

int main() {
    
    // Initialize array and k values for different tests
    int k1 = 12, k2 = 20;
    int myArr[40] = {3, 4, -12, 29, -6, 9, 24, -19, 8, -1,
                     14, 25, -25, 35, 7, -9, 18, -3, 43, 5,
                     37, 47, 30, 12, 26, -18, -7, 10, 22, 6,
                     38, 1, -14, 19, -20, -55, 90, -21, 11};
    
    // Look for the 12th smallest value in the entire array
    // Expected answer is -3
    cout << k1 << "th smallest element in full array: ";
    cout << kSmall(k1, myArr, 0, 39);
    cout << endl << endl;
    
    // Look for the 4th smallest value in array slice
    // Expected answer is 26
    cout << k2 << "th smallest element in array slice: ";
    cout << kSmall(k2, myArr, 5, 29);
    cout << endl << endl;
    
    return 0;
}

// Function definitions
int kSmall(int k, int anArray[], int first, int last)
{
    // Partition the array and get the pivot's index
    int pivotIndex = partition(anArray, first, last);
    int pivotValue = anArray[pivotIndex];

    // Use recursion algorithm
    if (k < pivotIndex - first + 1)
        return kSmall(k, anArray, first, pivotIndex - 1);
    else if (k == pivotIndex - first + 1)
        return pivotValue;
    else
        return kSmall(k - (pivotIndex - first + 1),
                      anArray, pivotIndex + 1, last);
}

int partition(int anArray[], int first, int last)
{
    // Use the first value of the array as pivot
    int pivotIndex = first;
    int leftIndex = first + 1;
    int rightIndex = last;
    
    // Loop over the array until left and right indexes cross
    while (leftIndex < rightIndex)
    {
        // If the element is smaller than the pivot, continue moving right
        while (anArray[leftIndex] <= anArray[pivotIndex] && leftIndex < last)
            leftIndex++;
        // If the element is larger than the pivot, continue moving left
        while (anArray[rightIndex] >= anArray[pivotIndex] && rightIndex > first)
            rightIndex--;
        // At this point,  either both indexes hit elements which need to be swapped,
        // or the indexes have crossed, and the loop will terminate.
        // If the indexes haven't crossed, swap elements at index positions
        if (leftIndex < rightIndex)
            swap(anArray[leftIndex], anArray[rightIndex]);
    }
    // Swap pivot element with the element of index crossing
    swap(anArray[rightIndex], anArray[pivotIndex]);
    
    return rightIndex;
}
