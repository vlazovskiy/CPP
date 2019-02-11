// Header file for class ClockTime 

const int max_hours = 24;
const int max_minutes = 60;

// Definition of ClockTime class.
class ClockTime {
private:
    
    int hour; // hours on 0-23 scale
    int minute; // minutes on 0-59 scale
    
    /* Helper function to print zero in front of
     single digit minute values.*/
    char addedZero() const;
    
    /* Helper function to print AM or PM part
     for the 12-hour format display.*/
    char amOrPm() const;
    
    /* Helper function to validate input values. */
    bool validateInput(int input_hour, int input_minute) const;
    
public:
    /* Default constructor: creates a time object and initializes
     it to a default value — 0 hours and 0 minutes.*/
    ClockTime();
    
    /* Constructor: creates a time object and initializes
     it to user provided input, if input is valid.
     Else prints an error message. */
    ClockTime(int input_hour, int input_minute);
    
    /* Sets time to user provided input if valid.
     Else prints an error message. */
    void setTime(int new_hour, int new_minute);
    
    /* Adds a number of minutes, if input is valid.
     Else prints an error message. */
    void addMinutes(int added_minutes);
    
    // Displays time in 24-hour notation.
    void displayAs24Notation() const;
    
    // Displays time in 12-hour notation.
    void displayAs12Notation() const;
    
};
