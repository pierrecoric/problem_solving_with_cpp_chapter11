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
};

ostream& operator <<(ostream& outs, const Complex& c) {
    outs << c.test;
    outs << ", proute: " << c.proute;
    return outs;
}


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
    friend bool operator == (const FunVector& vectorA, const FunVector<V>& vectorB);

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

template<class T>
FunVector<T>::FunVector() {
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<class T>
FunVector<T>::FunVector(int s) {
    data = new T [s];
    size = s;
    capacity = s;
}

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

template<class T>
void FunVector<T>::reserve(int needed) {
    if((size + needed) < capacity) {
        resize(needed + size);
    }
}

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





int main () {
    cout << "Test\n";
    Complex c, d;
    c.setTest(10);
    c.setProute(154);
    d.setTest(150);
    d.setProute(42);
    cout << c.getTest();
    FunVector<Complex> t;
    t.pushBack(c);
    t.pushBack(d);
    cout << t << "\n";
    t.changedataAt(0, d);
    cout << t << "\n";
    return 0;
}