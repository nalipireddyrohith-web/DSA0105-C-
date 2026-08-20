#include <iostream>
using namespace std;

class movieMagic {
    int year;
    string title;
    float rating;

public:
    void accept() {
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter rating: ";
        cin >> rating;
    }

    void display() {
        cout << "Title: " << title << endl;

        if(rating >= 0.0 && rating <= 2.0)
            cout << "Flop" << endl;
        else if(rating <= 3.4)
            cout << "Semi-hit" << endl;
        else if(rating <= 4.5)
            cout << "Hit" << endl;
        else
            cout << "Super Hit" << endl;
    }
};

int main() {
    movieMagic m;
    m.accept();
    m.display();
    return 0;
}
