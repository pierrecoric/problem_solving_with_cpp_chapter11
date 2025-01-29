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
        Money(double amount);
        Money(long dollars, int cents);

        //Function to add the values of two objects.
        friend Money add(const Money& amount1, const Money& amount2); 
        //Overloading the + operator
        friend Money operator +(const Money& amount1, const Money& amount2);

        //Function to subtract the values of two objects.
        friend Money sub(const Money& amount1, const Money& amount2);
        //Overloading the - operator
        friend Money operator -(const Money& amount1, const Money& amount2);

        //Overloading the - unary operator.
        friend Money operator -(const Money& amount);

        //Overloading the extraction operator
        friend ostream& operator <<(ostream& outs, const Money& amount);

        //Function that returns true if the amount of both parameters are the same.
        friend bool equal(const Money& amount1, const Money& amount2);
        //Overloading the == operator.
        friend bool operator ==(const Money& amount1, const Money& amount2);
        friend bool operator <(const Money& amount1, const Money& amount2);
        friend bool operator <=(const Money& amount1, const Money& amount2);
        friend bool operator >(const Money& amount1, const Money& amount2);
        friend bool operator >=(const Money& amount1, const Money& amount2);

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

//Constructor that takes the amount as a double.
Money::Money(double amount) {
    all_cents = amount * 100;
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

//Overloading the - unary operator.
Money operator -(const Money& amount) {
    return 0 - amount;
}

//Overloading the extraction operator.
ostream& operator <<(ostream& outs, const Money& amount) {
    bool neg(false);
    if(amount.all_cents < 0) {
        neg = true;
    }
    long positive_cents(0), dollars(0), cents(0);
    positive_cents = labs(amount.all_cents);
    if(amount.all_cents != 0) {
        dollars = positive_cents / 100;
        cents = positive_cents % 100;
    }
    if(neg) {
        outs << "-";
    }
    outs << "$" << dollars << "." << cents;
    return outs;
}

bool equal(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return equal(amount1, amount2);
}

bool operator <(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents < amount2.all_cents);
}

bool operator <=(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents <= amount2.all_cents);
}

bool operator >(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents > amount2.all_cents);
}

bool operator >=(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents >= amount2.all_cents);
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

//Output function

void Money::output(ostream& outs) const{
     bool neg(false);
    if(all_cents < 0) {
        neg = true;
    }
    long positive_cents(0), dollars(0), cents(0);
    positive_cents = labs(all_cents);
    if(all_cents != 0) {
        dollars = positive_cents / 100;
        cents = positive_cents % 100;
    }
    if(neg) {
        outs << "-";
    }
    outs << "$" << dollars << "." << cents;
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
    //Because a constructor that takes a double as a parameter, 25.32 is converted in the operation bellow to an Money object.
    m += 25.32;

    cout << m.get_value() << endl;

    m = -m;
    cout << m.get_value() << endl;

    cout << m << endl;


    return 0;
}