#include <iostream>
using namespace std;

class Worker {
protected:
    int code;
    string name;
    float salary;
public:
    void acceptWorker() {
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
    }
};

class Officer {
protected:
    float DA, HRA;
public:
    void acceptOfficer() {
        cout << "Enter DA: ";
        cin >> DA;
        cout << "Enter HRA: ";
        cin >> HRA;
    }
};

class Manager : public Worker, public Officer {
    float TA, gross_sal;
public:
    void calculate() {
        TA = salary * 0.10;
        gross_sal = salary + DA + HRA + TA;
    }

    void display() {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "TA: " << TA << endl;
        cout << "Gross Salary: " << gross_sal << endl;
    }
};

int main() {
    Manager m;
    m.acceptWorker();
    m.acceptOfficer();
    m.calculate();
    m.display();
    return 0;
}
