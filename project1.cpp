/*
1. In Chapter 8 we discussed vectors, which are like arrays that can grow in
size. Suppose that vectors were not defined in C++. Define a class called
VectorDouble that is like a class for a vector with base type double. Your
class VectorDouble will have a private member variable for a dynamic
array of doubles. It will also have two member variables of type int; one
called max_count for the size of the dynamic array of doubles; and one
called count for the number of array positions currently holding values.
(max_count is the same as the capacity of a vector; count is the same as the
size of a vector.)
If you attempt to add an element (a value of type double) to the vector
object of the class VectorDouble and there is no more room, then a new
dynamic array with twice the capacity of the old dynamic array is created
and the values of the old dynamic array are copied to the new dynamic array.Programming Projects
Your class should have all of the following:
■Three constructors: a default constructor that creates a dynamic array
for 50 elements, a constructor with one int argument for the number
of elements in the initial dynamic array, and a copy constructor.
■A destructor.
■A suitable overloading of the assignment operator =.
■A suitable overloading of the equality operator ==. To be equal, the
values of count and the count array elements must be equal, but the
values of max_count need not be equal.
■Member functions push_back, capacity, size, reserve, and resize
that behave the same as the member functions of the same names for
vectors.
■Two member functions to give your class the same utility as the
square brackets: value_at(i), which returns the value of the ith
element in the dynamic array; and change_value_at(d, i), which
changes the double value at the ith element of the dynamic array
to d. Enforce suitable restrictions on the arguments to value_at and
change_value_at. (Your class will not work with the square brackets.
It can be made to work with square brackets, but we have not covered
the material which tells you how to do that.)
*/

#include <iostream>
using std::cout;

class VectorDouble {
    private:
        double* value;
        int maxCount;
        int count;
    public:
        VectorDouble();
        VectorDouble(int elements);
        VectorDouble(VectorDouble& original);
        ~VectorDouble();
        VectorDouble operator =(VectorDouble& original);
        friend bool operator ==(const VectorDouble& vectorA, const VectorDouble& vectorB);
        void pushBack(double n);
        int capacity() const {return maxCount;}
        int size() const {return count;}
        void reserve(int size);
        void resize(int newSize);
        double valueAt(int i) {return value[i];}
        void changeValueAt(int i, double n) {value[i] = n;}
};

VectorDouble::VectorDouble() {
    value = nullptr;
    maxCount = 0;
    count  = 0;
}

VectorDouble::VectorDouble(int elements) {
    value = new double[elements];
    maxCount = elements;
    count = 0;
}

VectorDouble::VectorDouble(VectorDouble& original) {
    count = original.count;
    maxCount = original.maxCount;
    value = new double [maxCount];
    for(int i = 0; i < count; i++) {
        value[i] = original.value[i];
    }
}

VectorDouble::~VectorDouble() {
    if(value) {
        delete [] value;
        value = nullptr;
    }
}



void VectorDouble::pushBack(double n) {
    if(count < maxCount) {
        value[count] = n;
        count ++;
    }
    else {
        resize(2 * maxCount);
        pushBack(n);
    }
}

void VectorDouble::reserve(int size) {
    if((maxCount - count) < size) {
        resize(size);
    }
}

void VectorDouble::resize(int newSize) {
    double* temp;
    temp = new double[newSize];
    for(int i = 0; i < count; i++) {
        temp[i] = value[i];
    }
    delete value;
    value = temp;
    maxCount = newSize;
}

bool operator ==(const VectorDouble& vectorA, const VectorDouble& vectorB) {
    if(vectorA.count != vectorB.count) {
        return false;
    }
    for(int i = 0; i < vectorA.count; i ++) {
        if(vectorA.value[i] != vectorB.value[i]) {
            return false;
        }
    }
    return true;
}

VectorDouble VectorDouble::operator =(VectorDouble& rhs) {
    if(this != &rhs) {
        count = rhs.count;
        maxCount = rhs.maxCount;
        value = new double [maxCount];
        for(int i = 0; i < count; i++) {
            value[i] = rhs.value[i];
        }
    }
    return *this;
}

int main() {
    VectorDouble vc(10);
    vc.pushBack(10.01);
    cout << vc.valueAt(0) << "\n";
    for(int i = 0; i < 50; i++) {
        vc.pushBack(i+0.50);
    }
    cout << vc.size() << "\n";
    cout << vc.capacity() << "\n";
    
    for(int i = 0; i < vc.size(); i++) {
        cout << vc.valueAt(i) << "\n";
    }
    VectorDouble vc2(vc);
    cout << (vc == vc2) << "\n";
    vc2.changeValueAt(10, 43.3);
    cout << (vc == vc2) << "\n";
    vc = vc2;
    cout << (vc == vc2) << "\n";
    return 0;
}