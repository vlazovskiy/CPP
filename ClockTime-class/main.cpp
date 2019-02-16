// CS 110C, Spring 2019
// Instructor: Dr. Daniel O'Leary
// Assignment # 2, time of the day ADT implementation
// Vladimir Lazovskiy

/*Design and implement an ADT that represents the time of day. Represent the time as hours and minutes on a 24-hour clock. The hours and minutes are the private data members of the class that implements the ADT. Include at least two initialization operations: one that provides a default value for the time, and another that sets the time to a client-supplied value. These operations are the class’s constructors. Also include operations that set the time, increase the present time by a number of minutes, and display the time in 12-hour and 24-hour notations.*/

#include <iostream>
#include "ClockTime.hpp"
using namespace std;

int main() {
    
    // Initialize to default
    ClockTime time_1;
    
    // Initialize to user provided values
    ClockTime time_2(12, 20);
    
    /* Initialize to incorrect input.
     Excpected error message.*/
    ClockTime time_3(-12, 20);
    cout << endl;
    
    // Test functions
    time_1.addMinutes(50);
    time_1.displayAs12Notation();
    cout << endl;
    time_1.addMinutes(3841);
    time_1.displayAs24Notation();
    cout << endl;
    time_2.displayAs24Notation();
    cout << endl;
    time_2.addMinutes(720);
    time_2.displayAs24Notation();
    cout << endl;
    time_2.addMinutes(45);
    time_2.displayAs24Notation();
    cout << endl;
    time_2.setTime(25, 0);
    cout << endl;
    
    // Test invalid input. Expected error messages.
    time_2.setTime(2, -1);
    cout << endl;
    time_2.addMinutes(-30);
    cout << endl;
    
    /* This will not compile and correctly throw an error
     for trying to access a private member:
     time_1.minute; */
    cout << endl;
    
    return 0;
}
