/*
8. Give the complete definition of the member function get_value that you
would use with the definition of Money given in Display 11.4.
*/

#include <iostream>
using namespace std;


//Class for amounts of money in U.S. currency.
class Money {
    public:
        //Constructors
        Money();
        Money(long dollars);
        Money(long dollars, int cents);

        //Function to add the values of two objects.
        friend Money add(const Money& amount1, const Money& amount2); 
        //Overloading the + operator
        friend Money operator +(const Money& amount1, const Money& amount2);

        //Function to subtract the values of two objects.
        friend Money sub(const Money& amount1, const Money& amount2);
        //Overloading the - operator
        friend Money operator -(const Money& amount1, const Money& amount2);

        //Function that returns true if the amount of both parameters are the same.
        friend bool equal(const Money& amount1, const Money& amount2);
        //Overloading the == operator.
        friend bool operator ==(const Money& amount1, const Money& amount2);

        //Overloading the = operator.
        Money operator =(const Money& other);
        //Overloading the += operator.
        Money operator +=(const Money& other);
        //Overloading the -= operator.
        Money operator -=(const Money& other);

        double get_value() const;
        void input(istream& ins);
        void output(ostream& outs) const;

    private:
        long all_cents;
};

//Simple construtor
Money::Money() {
    all_cents = 0;
}

//Constructor with one parameter for the dollars.
Money::Money(long dollars) {
    all_cents = 100 * dollars;
}

//Constructor with a parameter for the dollars and one for the cents
Money::Money(long dollars, int cents) {
    all_cents = 100 * dollars + cents;
}

//Function to add two amounts to each other.
Money add(const Money& amount1, const Money& amount2) {
    Money result;
    result.all_cents = amount1.all_cents + amount2.all_cents;
    return result;
}

//Overloading the + operator.
Money operator +(const Money& amount1, const Money& amount2) {
    return add(amount1, amount2);
}

//Function to subtract two amounts to each other.
Money sub(const Money& amount1, const Money& amount2) {
    Money result;
    result.all_cents = amount1.all_cents - amount2.all_cents;
    return result;
}

//Overloading the - operator.
Money operator -(const Money& amount1, const Money& amount2) {
    return sub(amount1, amount2);
}

bool equal(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return equal(amount1, amount2);
}

//Overloading operators:
//=
Money Money::operator =(const Money& other) {
    if(this != &other) {
        all_cents = other.all_cents;
    }
    return *this;
}
//+=
Money Money::operator +=(const Money& other) {
    all_cents += other.all_cents;
    return *this;
}
//-=
Money Money::operator -=(const Money& other) {
    all_cents -= other.all_cents;
    return *this;
}

//Returns the value as a decimal number.
double Money::get_value() const{
    return all_cents / 100.0;
}


int main() {
    Money m(10, 50);
    Money n(10, 50);
    cout << m.get_value() << endl;
    cout << n.get_value() << endl;
    m = m + n;
    cout << m.get_value() << endl;

    if(m == n) {
        cout << "equal" << endl;
    } else cout << "not equal" << endl;
    n = m;
    Money c(1);
    if(m == n) {
        cout << "equal" << endl;
    } else cout << "not equal" << endl;

    m -= c;

    cout << m.get_value() << endl;

    return 0;
}