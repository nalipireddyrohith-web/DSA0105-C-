#include <iostream>
using namespace std;

class Item {
protected:
    int item_no;
    string name;
    float price;
public:
    void accept() {
        cout << "Enter item number: ";
        cin >> item_no;
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
    }
};

class DiscountedItem : public Item {
    float discount;
    float amount;
public:
    void calculate() {
        amount = price - (price * discount / 100);
    }

    void display() {
        cout << item_no << "\t" << name << "\t"
             << price << "\t" << discount << "%\t"
             << amount << endl;
    }

    void acceptDiscount() {
        cout << "Enter discount percentage: ";
        cin >> discount;
    }

    float getAmount() {
        return amount;
    }
};

int main() {
    int n;
    float total = 0;

    cout << "Enter number of items: ";
    cin >> n;

    DiscountedItem d[10];

    for(int i = 0; i < n; i++) {
        d[i].accept();
        d[i].acceptDiscount();
        d[i].calculate();
    }

    cout << "\nItem No\tName\tPrice\tDiscount\tAmount" << endl;

    for(int i = 0; i < n; i++) {
        d[i].display();
        total = total + d[i].getAmount();
    }

    cout << "Total Amount = " << total << endl;
    return 0;
}
