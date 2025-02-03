#include <iostream>
using std::cout;
using std::ostream;

class Complex {
    private:
        int test;
        int proute;
    public:
        void setTest(int n) {test = n;}
        void setProute(int n) {proute = n;}
        int getTest() {return test;}
        friend ostream& operator <<(ostream& outs, const Complex& c);
        friend bool operator ==(const Complex& conmplex1, const Complex& complex2);
        friend bool operator !=(const Complex& conmplex1, const Complex& complex2);
};

ostream& operator <<(ostream& outs, const Complex& c) {
    outs << c.test;
    outs << ", proute: " << c.proute;
    return outs;
}

bool operator ==(const Complex& conmplex1, const Complex& complex2) {
    if(conmplex1.proute == complex2.proute && conmplex1.test == complex2.test) {
        return true;
    } else return false;
}

bool operator !=(const Complex& conmplex1, const Complex& complex2) {
    if(conmplex1.proute != complex2.proute || conmplex1.test == complex2.test) {
        return false;
    } else return true;
}

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

        //Overloading some operators
        FunVector& operator =(const FunVector& rhs);

        template<class V>
        friend bool operator == (const FunVector<V>& vectorA, const FunVector<V>& vectorB);

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

//Reserve function
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







int main () {
    cout << "Test\n";
    Complex c, d;
    c.setTest(10);
    c.setProute(10);
    d.setTest(10);
    d.setProute(10);
    cout << c.getTest();
    FunVector<Complex> t;
    t.pushBack(c);
    t.pushBack(d);
    cout << t << "\n";
    t.changedataAt(0, d);
    cout << t << "\n";
    FunVector<Complex> x(t);
    x = t;
    cout << x << "\n";
    cout << (x == t) << "\n";
    return 0;
}