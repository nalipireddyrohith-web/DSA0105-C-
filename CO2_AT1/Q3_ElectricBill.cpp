#include <iostream>
using namespace std;

class ElectricBill {
    string n;
    int units;
    double bill;

public:
    void accept() {
        cout << "Enter customer name: ";
        cin >> n;
        cout << "Enter units: ";
        cin >> units;
    }

    void calculate() {
        if(units <= 100)
            bill = units * 2;
        else if(units <= 300)
            bill = 100 * 2 + (units - 100) * 3;
        else
            bill = 100 * 2 + 200 * 3 + (units - 300) * 5;

        if(units > 300)
            bill = bill + bill * 0.025;
    }

    void print() {
        cout << "Name of customer: " << n << endl;
        cout << "Number of units: " << units << endl;
        cout << "Bill amount: " << bill << endl;
    }
};

int main() {
    ElectricBill e;
    e.accept();
    e.calculate();
    e.print();
    return 0;
}
