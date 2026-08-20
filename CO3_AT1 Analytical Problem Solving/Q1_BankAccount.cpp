#include <iostream>
using namespace std;

class BankAccount {
    string name, type;
    int accno;
    float balance;

public:
    BankAccount(string n, int a, string t, float b) {
        name = n;
        accno = a;
        type = t;
        balance = b;
    }

    void deposit(int a, string n, float amount) {
        if(a == accno && n == name)
            balance = balance + amount;
        else
            cout << "Invalid account details" << endl;
    }

    void withdraw(float amount) {
        if(amount <= balance)
            balance = balance - amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    ~BankAccount() {
        cout << "Account closed" << endl;
    }
};

int main() {
    BankAccount b("Rohith", 1234, "Savings", 5000);

    b.deposit(1234, "Rohith", 2000);
    b.withdraw(1000);
    b.display();

    return 0;
}
