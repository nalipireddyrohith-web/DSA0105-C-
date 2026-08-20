#include <iostream>
using namespace std;

class Student {
protected:
    int m1, m2, m3;
public:
    void accept() {
        cout << "Enter three marks: ";
        cin >> m1 >> m2 >> m3;
    }
};

class Total : public Student {
protected:
    int total;
public:
    void findTotal() {
        total = m1 + m2 + m3;
    }
};

class Percentage : public Total {
public:
    void display() {
        float per = total / 3.0;
        cout << "Total = " << total << endl;
        cout << "Percentage = " << per << endl;
    }
};

int main() {
    Percentage p;
    p.accept();
    p.findTotal();
    p.display();
    return 0;
}
