#include <iostream>
using namespace std;

class books {
    string author, title, publisher;
    float price;
    int stock;

    void updatePrice(float p) {
        price = p;
    }

public:
    static int success, fail;

    books(string a, string t, float p, string pub, int s) {
        author = a;
        title = t;
        price = p;
        publisher = pub;
        stock = s;
    }

    void search(string t, string a, int copies) {
        if(title == t && author == a) {
            cout << "Book Available" << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: " << price << endl;
            cout << "Publisher: " << publisher << endl;

            if(copies <= stock) {
                cout << "Total Cost: " << price * copies << endl;
                stock = stock - copies;
                success++;
            }
            else {
                cout << "Required copies not in stock" << endl;
                fail++;
            }
        }
        else {
            cout << "Book not available" << endl;
            fail++;
        }
    }

    void changePrice(float p) {
        updatePrice(p);
    }
};

int books::success = 0;
int books::fail = 0;

int main() {
    books b("R.K.Narayan", "Malgudi", 500, "Penguin", 10);

    b.search("Malgudi", "R.K.Narayan", 2);

    b.changePrice(550);

    cout << "Successful Transactions: " << books::success << endl;
    cout << "Unsuccessful Transactions: " << books::fail << endl;

    return 0;
}
