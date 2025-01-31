#include <iostream>
using namespace std;

const int MAX_SIZE(50);

class TemperatureList {
    private:
        double list[MAX_SIZE];
        int size;
    public:
        TemperatureList();
        TemperatureList(TemperatureList& other);
        ~TemperatureList() {};
        void addTemperature(double temperature);
        bool full() const;
        friend ostream& operator <<(ostream& outs, const TemperatureList& t);
        int getSize() {return size;}
        double getTemperatureAt(int i);
};

void TemperatureList::addTemperature(double temperature) {
    if(full()){
        cout << "The list is full.";
    }
    else {
        list[size] = temperature;
        size ++;
    }
}

bool TemperatureList::full() const {
    return size == MAX_SIZE;
}

TemperatureList::TemperatureList() {
    size = 0;
}

TemperatureList::TemperatureList(TemperatureList& other) {
    for(int i = 0; i < other.size; i ++) {
        list[i] = other.list[i];
    }
    size = other.size;
}

ostream& operator <<(ostream& outs, const TemperatureList& t) {
    for(int i = 0; i < t.size; i++) {
        outs << "Entry #" << i << ": " << t.list[i];
    }
    return outs;
}

double TemperatureList::getTemperatureAt(int n) {
    if(n >= 0 || n < MAX_SIZE) {
        return list[n];
    } else cout << "Wrong input." << endl;
    return 0;
}

int main() {
    TemperatureList list;
    for(int i = 0; i < 5; i++) {
        cout << "Enter temperature point #" << i << ": ";
        double ans;
        cin >> ans;
        list.addTemperature(ans);
    } 
    cout << "output: " << endl;
    cout << list << endl;
    TemperatureList list2(list);
    cout << list2 << endl;

    cout << endl << list.getSize() << endl;
    cout << endl << list2.getSize() << endl;

    return 0;
}