#include <iostream>
using namespace std;

class Pairs {
    private:
        int x;
        int y;
    public:
        Pairs() : x(0), y(0) {};
        Pairs(int x, int y);
        friend istream& operator >>(istream& ins, Pairs& p);
        friend ostream& operator <<(ostream& outs, const Pairs& p);
        friend Pairs operator +(Pairs& a, Pairs& b);
        friend Pairs operator -(Pairs& a, Pairs& b);
        friend Pairs operator *(Pairs& a, int b);
};

Pairs::Pairs(int forX, int forY) {
    x = forX;
    y = forY;
}

istream& operator >>(istream& ins, Pairs& p) {
    char par1, par2, coma;
    int forX, forY;
    ins >> par1 >> forX >> coma >> forY >> par2;
    if(par1 != '(' || par2 != ')' || coma != ',') {
        cout << "Wrong input" << endl;
        exit(1);
    }
    p.x = forX;
    p.y = forY;
    return ins;
}

ostream& operator <<(ostream& outs, const Pairs& p) {
    outs << '(' << p.x << ',' << p.y << ')';
    return outs;
}

Pairs operator +(Pairs& a, Pairs& b) {
    Pairs temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    return temp;
}
Pairs operator -(Pairs& a, Pairs& b) {
    Pairs temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    return temp;
}
Pairs operator *(Pairs& a, int b) {
    Pairs temp;
    temp.x = a.x * b;
    temp.y = a.y * b;
    return temp;
}


//Ready

int main() {
    Pairs a(10,4);
    cout << a << endl; 
    cin >> a;
    cout << a << endl;
    Pairs b;
    cin >> b;
    cout << b << endl;
    a = a + b;
    cout << a << endl;
    a = a * 2;
    cout << a << endl;
    return 0;
}