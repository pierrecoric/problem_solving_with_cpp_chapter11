#include<iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

class Money {
    private:
        long allCents;
    public:
    Money() : allCents(0) {};
    Money(double amount);
    Money(long dollars, int cents);
    Money(const Money& other);

    //Arithmetics.
    //Add function.
    friend Money add(const Money& amount1, const Money& amount2);
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Subtract function.
    friend Money sub(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    //-unary operator
    friend Money operator -(const Money& amount);

    //Overloading insertion and extractions operators.
    void input(istream& ins);
    void output(ostream& outs);
    friend ostream& operator <<(ostream& outs, const Money& m);
    friend istream& operator >>(istream& ins, Money& m);

    //Comparisons.
    friend bool equal(const Money& amount1, const Money& amount2) {return amount1.allCents == amount2.allCents;}
    friend bool operator ==(const Money& amount1, const Money& amount2) {return amount1.allCents == amount2.allCents;}
    friend bool operator <(const Money& amount1, const Money& amount2) {return amount1.allCents < amount2.allCents;}
    friend bool operator >(const Money& amount1, const Money& amount2) {return amount1.allCents > amount2.allCents;}
    friend bool operator <=(const Money& amount1, const Money& amount2) {return amount1.allCents <= amount2.allCents;}
    friend bool operator >=(const Money& amount1, const Money& amount2) {return amount1.allCents >= amount2.allCents;}

    //Overloading the assignment operator.
    Money operator =(const Money& rhs);
    //Overloading the += / -= operators;
    Money operator +=(const Money& rhs);
    Money operator -=(const Money& rhs);

    double getValue() const {return allCents;}
    Money percent(double percentFigure) const;
};

Money::Money(double amount) {
    allCents = amount * 100;
}
Money::Money(long dollars, int cents) {
    allCents = dollars * 100 + cents;
}
Money::Money(const Money& other) {
    allCents = other.allCents;
}

//Arithmetics.
//Add function.
Money add(const Money& amount1, const Money& amount2) {
    return amount1.allCents + amount2.allCents;
}
Money operator +(const Money& amount1, const Money& amount2) {
    return add(amount1, amount2);
}
//Subtract function.
Money sub(const Money& amount1, const Money& amount2) {
    return amount1.allCents - amount2.allCents;
}
Money operator -(const Money& amount1, const Money& amount2) {
    return sub(amount1, amount2);
}
//-unary operator
Money operator -(const Money& amount) {
    return  - amount;
}


//Overloading insertion and extractions operators.
void Money::input(istream& ins) {
    double ans;
    cout << "Enter the value including the decimals";
    ins >> ans;
    allCents = ans * 100;
}

void Money::output(ostream& outs) {
    long currentCents = allCents;
    long dollars(0); 
    int cents(0);
    bool neg = currentCents;
    if (neg) {
        outs << "-";
        currentCents = currentCents + (currentCents * -2);
    }
    outs << "$";

    dollars = currentCents / 100;
    cents = currentCents % 100;
    outs << dollars << '.' << cents;
}

ostream& operator <<(ostream& outs, const Money& m) {
    long currentCents = m.allCents;
    long dollars(0); 
    int cents(0);
    bool neg = currentCents < 0;
    if (neg) {
        outs << "-";
        currentCents = currentCents + (currentCents * -2);
    }
    outs << "$";

    dollars = currentCents / 100;
    cents = currentCents % 100;
    outs << dollars << '.' << cents;
    return outs;
}
istream& operator >>(istream& ins, Money& m) {
    double ans;
    ins >> ans;
    m.allCents = ans * 100;
    return ins;
}

//Overloading the assignment operator.
Money Money::operator =(const Money& rhs) {
    if(&rhs != this) {
        allCents = rhs.allCents;
    } return *this;
}
//Overloading the += / -= operators;
Money Money::operator +=(const Money& rhs) {
    allCents += rhs.allCents;
    return *this;
}
Money Money::operator -=(const Money& rhs) {
    allCents -= rhs.allCents;
    return *this;
}


Money Money::percent(double percentFigure) const {
    double mult = 1.0 / 100 * percentFigure;
    return allCents / 100 * mult;
}

int main() {
    return 0;
}