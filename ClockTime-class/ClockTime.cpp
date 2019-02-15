// Class ClockTime implementation

#include "ClockTime.hpp"
#include <iostream>
using namespace std;

ClockTime::ClockTime() {
    hour = 0;
    minute = 0;
}

ClockTime::ClockTime(int input_hour, int input_minute) {
    if (validateInput(input_hour, input_minute)) {
        hour = input_hour;
        minute = input_minute;
    }
    else {
        cout << "Invalid input. Please try again.";
        return;
    }
}

char ClockTime::addedZero() const {
        char added_zero;
        if (minute < 10)
            added_zero = '0';
        else
            added_zero = '\0';
        return added_zero;
    }
    
char ClockTime::amOrPm() const {
        char am_or_pm;
        if ((hour / max_hours) < 12)
            am_or_pm = 'a';
        else
            am_or_pm = 'p';
        return am_or_pm;
    }

bool ClockTime::validateInput(int input_hour,
                              int input_minute) const {
    if (input_hour <= max_hours && input_hour >= 0 &&
        input_minute >= 0 && input_minute <= max_minutes)
        return true;
    else
        return false;
}
    
void ClockTime::setTime(int new_hour, int new_minute) {
        if (validateInput(new_hour, new_minute)) {
            hour = new_hour;
            minute = new_minute;
        }
        else {
            cout << "Invalid input. Please try again.";
            return;
        }
    }
    
void ClockTime::addMinutes(int added_minutes) {
    if (added_minutes >= 0) {
            int new_minute = minute + added_minutes;
            int new_hour = hour + new_minute / max_minutes;
            hour = new_hour % max_hours;
            minute = new_minute % max_minutes;
    }
    else {
        cout << "Invalid input. Please try again.";
        return;
    }
}
    
void ClockTime::displayAs24Notation() const {
        cout << "The time is: " << hour << ":"
        << addedZero() << minute;
    }
    
void ClockTime::displayAs12Notation() const {
        int displayed_hour = hour % max_hours;
        cout << "The time is: " << displayed_hour
        << ":" << addedZero() << minute
        << amOrPm() << "m";
    }
