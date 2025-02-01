#include <iostream>
using std::cout, std::cin, std::ostream, std::array;

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
    } else cout << "Wrong input.\n";
    return 0;
}

int main() {
    array<int, 256> test;
    test[0] = 3;
    cout << test[0] << "\n";
    TemperatureList list;
    for(int i = 0; i < 5; i++) {
        cout << "Enter temperature point #" << i << ": ";
        double ans;
        cin >> ans;
        list.addTemperature(ans);
    } 
    cout << "output: \n";
    cout << list << "\n";
    TemperatureList list2(list);
    cout << list2 << "\n";

    cout << "\n" << list.getSize() << "\n";
    cout << "\n" << list2.getSize() << "\n";

    return 0;
}