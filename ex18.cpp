#include <iostream>
using namespace std;

class Percent {
	private:
		int value;
	public:
		Percent() : value(0) {};
		Percent(int n) {value = n;}
		friend ostream& operator <<(ostream& outs, const Percent& p);
		friend istream& operator >>(istream& ins, Percent& p);
};

ostream& operator <<(ostream& outs, const Percent& p) {
	outs << p.value << '%';
	return outs;
}

istream& operator >>(istream& ins, Percent& p) {
	int v;
	char perc;
	ins >> v >> perc;
	if(perc != '%') {
		cout << "wrong input" << endl;
		exit(1);
	}
    //This line does not seem to have an effect.
	p.value = v;
	return ins;
}

int main() {
	Percent test(99);
	cout << test << endl;
	cin >> test;
    //the value of test has not been changed
	cout << "New input: " << test << endl;
	return 0;
}