#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

/*
Define a class for complex numbers. A complex number is a number of the
form
a+b*i
where, for our purposes, a and b are numbers of type double, and i is a
number that represents the quantity √ −1. Represent a complex number
as two values of type double. Name the member variables real and
imaginary. (The variable for the number that is multiplied by i is the one
called imaginary.) Call the class Complex.
Include a constructor with two parameters of type double that can be
used to set the member variables of an object to any values. Also include
a constructor that has only a single parameter of type double; call this
parameter real_part and define the constructor so that the object will
be initialized to real_part+0*i. Also include a default constructor that
initializes an object to 0 (that is, to 0+0*i). Overload all of the following
operators so that they correctly apply to the type Complex: ==, +, -, *, >>,
and <<. You should write a test program to test your class.

(Hints: To add or subtract two complex numbers, you add or subtract
the two member variables of type double. The product of two complex
numbers is given by the following formula:
(a + b*i)*(c + d*i) == (a*c – b*d) + (a*d + b*c)*i
In the interface file, you should define a constant i as follows:
const Complex i(0, 1);
This defined constant i will be the same as the i discussed earlier.
delete p;
*/


////////////////////////////////////////////////////////////////////////////////////////////////////Complex
class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex() : real(0), imaginary(0) {}
        Complex(double r);
        Complex(double r, double i);
        Complex(const Complex& c);
        ~Complex() {}
        friend ostream& operator <<(ostream& outs, const Complex& c);
        friend istream& operator >>(istream& ins, Complex& c);
        //Overloading arithmetics operator.
        Complex operator +(const Complex& rhs);
        Complex operator -(const Complex& rhs);
        Complex operator /(const Complex& rhs);
        Complex operator *(const Complex& rhs);
        friend bool operator ==(const Complex& conmplex1, const Complex& complex2);
        friend bool operator !=(const Complex& conmplex1, const Complex& complex2);
};

Complex::Complex(double r) {
    real = r;
    imaginary = 0;
}

Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}

Complex::Complex(const Complex& c) {
    real = c.real;
    imaginary = c.imaginary;
}

//Defining i.
const Complex i(0,1);

ostream& operator <<(ostream& outs, const Complex& c) {
    outs << "(" << c.real << "+" << c.imaginary << "*i)";
    return outs;
}

istream& operator >>(istream& ins, Complex& c) {
    //a+b*i
    char plus, mult, ii;
    double a, b;
    ins >> a >> plus >> b >> mult >> ii;
    if(plus != '+' || mult != '*' || ii != 'i') {
        cout << "Wrong input \n";
    }
    else {
        c.real = a;
        c.imaginary = b;
    }
    return ins;
}

//Overloading arithmetics operator.
Complex Complex::operator +(const Complex& rhs) {
    Complex temp;
    temp.imaginary = imaginary + rhs.imaginary;
    temp.real = real + rhs.real;
    return temp;
}

Complex Complex::operator -(const Complex& rhs) {
    Complex temp;
    temp.imaginary = imaginary - rhs.imaginary;
    temp.real = real - rhs.real;
    return temp;
}

Complex Complex::operator /(const Complex& rhs) {
    Complex temp;
    temp.real = (real / rhs.real) - (imaginary / rhs.imaginary);
    temp.imaginary = (real / rhs.imaginary) - (imaginary / rhs.real);
    return temp;
}

Complex Complex::operator *(const Complex& rhs) {
    Complex temp;
    temp.real = (real * rhs.real) - (imaginary * rhs.imaginary);
    temp.imaginary = (real * rhs.imaginary) - (imaginary * rhs.real);
    return temp;
}

bool operator ==(const Complex& conmplex1, const Complex& complex2) {
    if(conmplex1.real == complex2.real && conmplex1.imaginary == complex2.imaginary) {
        return true;
    } else return false;
}

bool operator !=(const Complex& conmplex1, const Complex& complex2) {
    if(conmplex1.real != complex2.real || conmplex1.imaginary == complex2.imaginary) {
        return false;
    } else return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Complex

////////////////////////////////////////////////////////////////////////////////////////////////////FunVector
//Templated vector class to understand templates.
template<class T>
class FunVector {
    private:
        T* data;
        int size;
        int capacity;
    public:
        //Default constructor.
        FunVector();
        //Constructor with a specific size.
        FunVector(int s);
        //Copy constructor.
        FunVector(const FunVector& v);

        //Destructor
        ~FunVector() {delete [] data;}

        //Overloading some operators
        FunVector& operator =(const FunVector& rhs);

        //Overloading ==
        template<class V>
        friend bool operator == (const FunVector<V>& vectorA, const FunVector<V>& vectorB);

        //Overloading <<.
        template<class V>
        friend ostream& operator<< (ostream& outs, const FunVector<V>& v);

        //Members functions.
        void pushBack(T t);
        int getCapacity() const {return capacity;}
        int getSize() const {return size;}
        void reserve(int needed);
        void resize(int newSize);
        T dataAt(int i) {return data[i];}
        void changedataAt(int i, T& t) {data[i] = t;}

};

//Default constructor.
template<class T>
FunVector<T>::FunVector() {
    data = nullptr;
    size = 0;
    capacity = 0;
}

//Constructor that specifies the size.
template<class T>
FunVector<T>::FunVector(int s) {
    data = new T [s];
    size = s;
    capacity = s;
}

//Copy constructor.
template<class T>
FunVector<T>::FunVector(const FunVector& v) {
    size = v.size;
    capacity = v.capacity;
    data = new T[capacity];
    for(int i = 0; i < size; i++) {
        data[i] = v.data[i];
    }
}

//Overloading =.
template<class T>
FunVector<T>& FunVector<T>::operator =(const FunVector& rhs) {
    if(this != &rhs) {
        size = rhs.size;
        capacity = rhs.capacity;
        data = new T [capacity];
        for(int i = 0; i < size; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

//Overloading ==.
template<class T>
bool operator == (const FunVector<T>& vectorA, const FunVector<T>& vectorB) {
    if(vectorA.size != vectorB.size) {
        return false;
    }
    else {
        for(int i =0; i < vectorA.size; i++) {
            if(vectorA.data[i] != vectorB.data[i]) {
                return false;
            }
        }
    }
    return true;
}

//Overloading <<.
template<class T>
ostream& operator <<(ostream& outs, const FunVector<T>& v) {
    outs << "[";
    for(int i = 0; i < v.size; i++) {
        outs << v.data[i];
        if(i < v.size - 1) {
            outs << ", ";
        }
    }
    outs << "]"; 
    return outs;
}

//Push back function.
template<class T>
void FunVector<T>::pushBack(T t) {
    if(size < capacity) {
        data[size] = t;
        size ++;
    }
    else {
        if(capacity == 0) {
            resize(1);
        } else resize(2 * size);
        pushBack(t);
    }
}

//Reserve function.
template<class T>
void FunVector<T>::reserve(int needed) {
    if((size + needed) < capacity) {
        resize(needed + size);
    }
}

//Resize function.
template<class T>
void FunVector<T>::resize(int newSize) {
    T* temp; 
    temp = new T[newSize];
    for(int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    capacity = newSize;
}
////////////////////////////////////////////////////////////////////////////////////////////////////FunVector

//Test
int main () {
    cout << "Test\n";
    Complex c, d, e;
    cin >> c;
    cin >> d;
    cin >> e;
    FunVector<Complex> t;
    t.pushBack(c);
    t.pushBack(d);
    t.pushBack(e);
    t.pushBack(c + d);
    t.pushBack(c * d);
    cout << t << "\n";

    return 0;
}