#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isPalindrome(const string&);

int main() {
    
    cout << isPalindrome("abcdcba") << endl;
    cout << isPalindrome("abcd") << endl;
    cout << isPalindrome("a") << endl;
    cout << isPalindrome("") << endl; // empty string is a palindrome
    
    return 0;
}

bool isPalindrome(const string& aString)
{
    /* Start by creating a stack and populating it with string
     characters in the order they appear in the string. */
    stack <char> myStack;
    int i = 0;
    char currChar = aString[i];
    while (currChar != '\0')
    {
        myStack.push(currChar);
        i++;
        currChar = aString[i];
    }
    /* Now reset indices and loop over the string again, but
     this time look at the last stack element, compare it to
     current string element and pop it, if it matches the current
     string character.
     
     Set bool variable isPalindrome to true in the beginning.
     If the loop executes fully, then the string is a palindrome.
     If not, the loop terminates early. When characters don't match,
     we will know it's not a palindrome without checking the whole string.
     
     We also don't need to check if the stack is empty, since it was
     constructed from the string, and their lengths match. */
    i = 0;
    currChar = aString[i];
    char stackTop;
    bool isPalindrome = true;
    while (isPalindrome && currChar != '\0')
    {
        stackTop = myStack.top();
        if (stackTop == currChar)
        {
            myStack.pop();
            i++;
            currChar = aString[i];
        }
        else
            isPalindrome = false;
    }
    return isPalindrome;
}
