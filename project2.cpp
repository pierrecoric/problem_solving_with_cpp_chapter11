/*
2. Define a class for rational numbers. A rational number is a number that
can be represented as the quotient of two integers. For example, 1/2, 3/4,
64/2, and so forth are all rational numbers. (By 1/2, etc., we mean the
everyday meaning of the fraction, not the integer division this expression
would produce in a C++ program.) Represent rational numbers as two val-
ues of type int, one for the numerator and one for the denominator. Call
the class Rational.
Include a constructor with two arguments that can be used to set the
member variables of an object to any legitimate values. Also include a
constructor that has only a single parameter of type int; call this single
parameter whole_number and define the constructor so that the object
will be initialized to the rational number whole_number/1. Also include a
default constructor that initializes an object to 0 (that is, to 0/1).
Overload the input and output operators >> and <<. Numbers are to be
input and output in the form 1/2, 15/32, 300/401, and so forth. Note
that the numerator, the denominator, or both may contain a minus
sign, so -1/2, 15/32, and -300/-401 are also possible inputs. Overload
all of the following operators so that they correctly apply to the type
Rational: ==, <, <=, >, >=, +, -, *, and /. Also write a test program to test
your class.
695696
Chapter 11 / Friends, Overloaded Operators, and Arrays in Classes
(Hints: Two rational numbers a/b and c/d are equal if a*d equals
c*b. If b and d are positive rational numbers, a/b is less than c/d
provided a*d is less than c*b. You should include a function to nor-
malize the values stored so that, after normalization, the denomi-
nator is positive and the numerator and denominator are as small
as possible. For example, after normalization 4/-8 would be repre-
sented the same as -1/2. You should also write a test program to test
your class.)
*/

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

class Rational;
int gcd(int a, int b);
int reverseSign(int n);
Rational operationFun(istream& ins);

class Rational {
    private:
        int numerator;
        int denominator;
    public:
        Rational() : numerator(0), denominator(1) {};
        Rational(int n);
        Rational(int n, int d);
        Rational(Rational& r);
        ~Rational() {};
        //Overloading << and >>
        friend ostream& operator <<(ostream& outs, const Rational& number);
        friend istream& operator >>(istream& outs, Rational& number);
        //Overloading operators:
        friend bool operator ==(const Rational& number1, const Rational& number2);
        friend bool operator <(const Rational& number1, Rational& number2);
        friend bool operator <=(const Rational& number1, Rational& number2);
        friend bool operator >(const Rational& number1, Rational& number2);
        friend bool operator >=(const Rational& number1, Rational& number2);
        //Overloading arithmetics operator.
        Rational operator +(Rational& rhs);
        Rational operator -(Rational& rhs);
        Rational operator /(Rational& rhs);
        Rational operator *(Rational& rhs);
        Rational& operator =(const Rational& rhs);
        //Helper function to normalize the fraction.
        void normalize();
};

//Default construtor.
Rational::Rational(int n) {
    denominator = 1;
    numerator = n;
}
//Constructor to specify the numerator and the denominator.
Rational::Rational(int n, int d) {
    if(denominator != 0) {
        denominator = d;
    } else denominator = 1;
    numerator = n;
}
//Copy constructor.
Rational::Rational(Rational& r) {
    numerator = r.numerator;
    denominator = r.denominator;
}

//Overloading << and >>
//<<
ostream& operator <<(ostream& outs, const Rational& number) {
    if(number.denominator == 1) {
        outs << number.numerator;
    }
    else outs << number.numerator << "/" << number.denominator;
    return outs;
}
//>>
istream& operator >>(istream& ins, Rational& number) {
    int n, d;
    char t;
    ins >> n >> t >> d;
    if(d == 0 || t != '/') {
        cout << "Wrong input. I set the number to 0 \n";
        n = 0;
        d = 1;
        t = '/';
    }
    else {
        number.numerator = n;
        number.denominator = d;
    }
    return ins;
}
//Overloading operators:
bool operator ==(const Rational& number1, const Rational& number2) {
    return ((number1.numerator * number2.denominator) == (number2.numerator * number1.denominator));
}

//Overloading comparison operators.
// <
bool operator <(const Rational& number1, Rational& number2) {
    int num1(number1.numerator), num2(number2.numerator);
    int den1(number1.denominator), den2(number2.denominator);
    num1 *= den2;
    num2 *= den1;
    den1 *= den2;
    return num1 < num2;
}
// <=
bool operator <=(const Rational& number1, Rational& number2) {
    int num1(number1.numerator), num2(number2.numerator);
    int den1(number1.denominator), den2(number2.denominator);
    num1 *= den2;
    num2 *= den1;
    den1 *= den2;
    return num1 <= num2;
    
}
// >
bool operator >(const Rational& number1, Rational& number2) {
    int num1(number1.numerator), num2(number2.numerator);
    int den1(number1.denominator), den2(number2.denominator);
    num1 *= den2;
    num2 *= den1;
    den1 *= den2;
    return num1 > num2;
}
// >=
bool operator >=(const Rational& number1, Rational& number2) {
    int num1(number1.numerator), num2(number2.numerator);
    int den1(number1.denominator), den2(number2.denominator);
    num1 *= den2;
    num2 *= den1;
    den1 *= den2;
    return num1 >= num2;
}

//Overloading arithmetics operator.
//+
Rational Rational::operator +(Rational& rhs) {
    Rational temp;
    temp.numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    temp.denominator = denominator * rhs.denominator;
    temp.normalize();
    return temp;
}
//-
Rational Rational::operator -(Rational& rhs) {
    Rational temp;
    temp.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    temp.denominator = denominator * rhs.denominator;
    temp.normalize();
    return temp;
}
// /
Rational Rational::operator /(Rational& rhs) {
    Rational temp;
    temp.numerator = numerator / rhs.numerator;
    temp.denominator = denominator / rhs.denominator;
    temp.normalize();
    return temp;
}
// *
Rational Rational::operator *(Rational& rhs) {
    Rational temp;
    temp.numerator = numerator * rhs.numerator;
    temp.denominator = denominator * rhs.denominator;
    temp.normalize();
    return temp;
}

//Overloading the assignemtn operator
Rational& Rational::operator =(const Rational& rhs) {
    if(this != &rhs) {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
    }
    return *this;
}

//Helper function to normalize the fraction.
void Rational::normalize() {
    if(numerator != 0) {
        int g = gcd(numerator, denominator);
        numerator = numerator / g;
        denominator = denominator / g;
    }
    else {
        numerator = 0;
        denominator = 1;
    }
    if(numerator < 0 && denominator < 0) {
        numerator = reverseSign(numerator);
        denominator = reverseSign(denominator);
    }
    else if(denominator < 0) {
        numerator = reverseSign(numerator);
        denominator = reverseSign(denominator);
    }
}

//Helper function that returns the gcd.
int gcd(int a, int b) {
    if(a == b) {
        return a;
    }
    if(a < 0) {
        a = reverseSign(a);
    }
    if(b < 0) {
        b = reverseSign(b);
    }
    int gcd;
    gcd = (a < b) ? a : b;
    while(gcd > 0) {
        if(a % gcd == 0 && b % gcd == 0) {
            break;
        }
        gcd --;
    }
    return gcd;
}


Rational operationFun(istream& ins) {
    Rational a, b;
    char oper;
    ins >> a >> oper >> b;
    switch (oper) {
        case '+':
            return a + b;
            break;

        case '-':
            return a - b;
            break;

        case '/':
            return a / b;
            break;

        case '*':
            return a * b;
            break;
    
        default:
            cout << "wron input\n";
            a = (0,1);
            return a;
            break;
    }
}

//Test
int main() {
    Rational a, b;
    cin >> a;
    cin >> b;
    cout << a * b << "\n";
    Rational c = operationFun(cin);
    cout << c << "\n";
}

int reverseSign(int n) {
    return -n;
}


