/*
8. Give the complete definition of the member function get_value that you
would use with the definition of Money given in Display 11.4.
*/

#include <iostream>
using namespace std;


int digit_to_int(char c);

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

        //Overloading the extraction operator.
        friend ostream& operator <<(ostream& outs, const Money& amount);

        //Overloading the insertion operator.
        friend istream& operator >>(istream& ins, Money& amount);

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

//Overloading the insertion operator.
istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool neg(false);
    
    ins >> one_char;
    if(one_char == '-') {
        neg = true;
        ins >> one_char;
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if(one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "wrong input" << endl;
        dollars = 0;
        cents = 0;
        neg = false;
        digit1 = '0';
        digit2 = '0';
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if(neg) {
        amount.all_cents = - amount.all_cents;
    }
    return ins;
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
    Money moneyArr [5];
    cout << "valid formats: (-)$x.xx" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Enter amount #" << i + 1 << " :";
        cin >> moneyArr[i];
        moneyArr[i] = moneyArr[i].get_value() * 2;
    }
    cout << endl;
    for(int i = 0; i < 5; i ++) {
        cout << "Amount #" << i + 1 << ": " << moneyArr[i] << endl;
    }

    return 0;
}

int digit_to_int(char c) {
    return c - '0';
}