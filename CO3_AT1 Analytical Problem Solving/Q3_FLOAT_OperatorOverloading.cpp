#include <iostream>
using namespace std;

class FLOAT {
    float x;

public:
    FLOAT(float a = 0) {
        x = a;
    }

    FLOAT operator+(FLOAT f) {
        return FLOAT(x + f.x);
    }

    FLOAT operator-(FLOAT f) {
        return FLOAT(x - f.x);
    }

    FLOAT operator*(FLOAT f) {
        return FLOAT(x * f.x);
    }

    FLOAT operator/(FLOAT f) {
        return FLOAT(x / f.x);
    }

    void display() {
        cout << x << endl;
    }
};

int main() {
    FLOAT a(10.5), b(2.5);
    FLOAT c;

    c = a + b;
    cout << "Addition: ";
    c.display();

    c = a - b;
    cout << "Subtraction: ";
    c.display();

    c = a * b;
    cout << "Multiplication: ";
    c.display();

    c = a / b;
    cout << "Division: ";
    c.display();

    return 0;
}
