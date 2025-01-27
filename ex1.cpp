/*
1. Write a function definition for a function called before that takes two
arguments of the type DayOfYear, which is defined in Display 11.1.
The function returns a bool value and returns true if the first argument
represents a date that comes before the date represented by the second
argument; otherwise, the function returns false; for example, January 5
comes before February 2.
*/

#include <iostream>
using namespace std;
class DayOfYear
{
    public:
        //Simple constructor: initializes the day to January 1st.
        DayOfYear(): month(1), day(1) {}
        //Constructor that takes in parameters.
        DayOfYear(int the_month, int the_day);
        //Copy constructor.
        DayOfYear(DayOfYear& original);
        //Destructor.
        ~DayOfYear(){};
        void input();
        void output() const;

        int get_month() const {return month;} 
        //Returns the month, 1 for January, 2 for February, etc.
        int get_day() const {return day;}
        //Returns the day of the month.
    private:
        void check_date() const;
        int month;
        int day;
};

DayOfYear::DayOfYear(int the_month, int the_day) {
    if(the_day > 0 && the_day <= 31) {
        day = the_day;
    }
    else {
        cout << "Input error day: " << the_day << " is invalid. Initializing to the 1st" << endl;
        day = 1;
    }
    if(the_month > 0 &&  the_month <= 12) {
        month = the_month;
    }
    else {
        cout << "Input error month: " << the_month << " is invalid. Initializing to January" << endl;
        month = 1;
    }
}

DayOfYear::DayOfYear(DayOfYear& original) {
    day = original.day;
    month = original.month;
}

void DayOfYear::input() {
    int ans;
    cout << "Enter the day: ";
    cin >> ans;
    day = ans;
    cout << "Enter the month: ";
    cin >> ans;
    month = ans;
    check_date();
}

void DayOfYear::output() const {
    cout << "Day: " << day << endl;
    cout << "Month: " << month << endl;
}

void DayOfYear::check_date() const {
    if(day < 1 || day > 31) {
        cout << "invalid date. Terminating." << endl;
        exit(1);
    }
    if(month < 1 || month > 12) {
        cout << "invalid date. Terminating." << endl;
        exit(1);
    }
    if(month == 4 || month == 6 || month == 9 || month == 10) {
        if(day > 30) {
            cout << "invalid date. Terminating." << endl;
            exit(1);
        }
    }
    if(month == 2) {
        if(day > 29) {
            cout << "invalid date. Terminating." << endl;
            exit(1);
        }
    }
}


bool before(DayOfYear A, DayOfYear B);



int main() {
    DayOfYear day(12, 5);
    day.output();
    day.input();
    day.output();
    DayOfYear day2(day);
    day2.output();
    day2.input();
    if(before(day, day2)) {
        cout << day.get_day() << "/" << day.get_month() << " comes before " << day2.get_day() << "/" << day2.get_month() << endl;
    } else cout << day.get_day() << "/" << day.get_month() << " comes after " << day2.get_day() << "/" << day2.get_month() << endl;
    
    cout << "End of program." << endl;
    return 0;
}


bool before(DayOfYear A, DayOfYear B) {
    //Months are the same.
    if(A.get_month() == B.get_month()) {
        //A comes Before.
        if(A.get_day() < B.get_day()) {
            return true;
        } else return false;//A is the same or comes after.
    }
    //A comes before.
    else if(A.get_month() < B.get_month()) { 
        return true;
    } else return false; //A comes after.
}