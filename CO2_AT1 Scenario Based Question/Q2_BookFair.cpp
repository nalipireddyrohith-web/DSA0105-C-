#include <iostream>
using namespace std;

class BookFair {
    string Bname;
    double price;

public:
    void Input() {
        cout << "Enter book name: ";
        cin >> Bname;
        cout << "Enter price: ";
        cin >> price;
    }

    void calculate() {
        if(price <= 1000)
            price = price - price * 0.02;
        else if(price <= 3000)
            price = price - price * 0.10;
        else
            price = price - price * 0.15;
    }

    void display() {
        cout << "Book Name: " << Bname << endl;
        cout << "Price after discount: " << price << endl;
    }
};

int main() {
    BookFair b;
    b.Input();
    b.calculate();
    b.display();
    return 0;
}
