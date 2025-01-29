/*
8. Give the complete definition of the member function get_value that you
would use with the definition of Money given in Display 11.4.
*/

#include <iostream>
using namespace std;


//Class for amounts of money in U.S. currency.
class Money {
    public:
        friend Money add(const Money& amount1, const Money& amount2);
        //Precondition: amount1 and amount2 have been given values.
        //Returns the sum of the values of amount1 and amount2.

        friend Money operator +(const Money& amount1, const Money& amount2);

        friend bool equal(const Money& amount1, const Money& amount2);
        //Precondition: amount1 and amount2 have been given values.
        //Returns true if amount1 and amount2 have the same value;
        //otherwise, returns false.

        friend bool operator ==(const Money& amount1, const Money& amount2);

        Money operator =(const Money& other);

        Money(long dollars, int cents);
        //Initializes the object so its value represents an amount with the
        //dollars and cents given by the arguments. If the amount is negative,
        //then both dollars and cents must be negative.

        Money(long dollars);
        //Initializes the object so its value represents $dollars.00.

        Money();
        //Initializes the object so its value represents $0.00.

        double get_value() const;
        //Precondition: The calling object has been given a value.
        //Returns the amount of money recorded in the data of the calling object.

        void input(istream& ins);
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file. An amount of money, including a dollar sign, has been
        //entered in the input stream ins. Notation for negative amounts is -$100.00.
        //Postcondition: The value of the calling object has been set to
        //the amount of money read from the input stream ins.

        void output(ostream& outs) const;
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.
        //Postcondition: A dollar sign and the amount of money recorded
        //in the calling object have been sent to the output stream outs.

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

//Returns the value as a decimal number.
double Money::get_value() const{
    return all_cents / 100.0;
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

bool equal(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return equal(amount1, amount2);
}

Money Money::operator =(const Money& other) {
    if(this != &other) {
        all_cents = other.all_cents;
    }
    return *this;
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
    if(m == n) {
        cout << "equal" << endl;
    } else cout << "not equal" << endl;


    return 0;
}