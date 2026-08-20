#include <iostream>
#include <string>
using namespace std;

class String {
    string s;

public:
    String(string a) {
        s = a;
    }

    bool operator==(String x) {
        return s == x.s;
    }

    bool operator>(String x) {
        return s > x.s;
    }

    bool operator<(String x) {
        return s < x.s;
    }
};

int main() {
    String a("Rohith");
    String b("Ravi");

    if(a == b)
        cout << "Both strings are equal" << endl;
    else if(a > b)
        cout << "First string is greater" << endl;
    else
        cout << "First string is smaller" << endl;

    return 0;
}
