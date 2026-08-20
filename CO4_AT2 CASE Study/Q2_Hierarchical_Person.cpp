#include <iostream>
using namespace std;

class Person {
protected:
    string name, address;
    long phone_no;
public:
    void acceptPerson() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone_no;
    }
};

class Employee : public Person {
    int eno;
    string ename;
public:
    void accept() {
        acceptPerson();
        cout << "Enter employee number: ";
        cin >> eno;
        cout << "Enter employee name: ";
        cin >> ename;
    }

    void display() {
        cout << "Employee No: " << eno << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone_no << endl;
    }
};

class Manager : public Person {
    string designation, department_name;
    float basic_salary;
public:
    void accept() {
        acceptPerson();
        cout << "Enter designation: ";
        cin >> designation;
        cout << "Enter department: ";
        cin >> department_name;
        cout << "Enter basic salary: ";
        cin >> basic_salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department: " << department_name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone_no << endl;
    }

    float getSalary() {
        return basic_salary;
    }

    string getName() {
        return name;
    }
};

int main() {
    int n;
    cout << "Enter number of employees and managers: ";
    cin >> n;

    Employee e[10];
    Manager m[10];

    cout << "Enter employee details:" << endl;
    for(int i = 0; i < n; i++)
        e[i].accept();

    cout << "Enter manager details:" << endl;
    for(int i = 0; i < n; i++)
        m[i].accept();

    cout << "\nEmployee Details:" << endl;
    for(int i = 0; i < n; i++)
        e[i].display();

    cout << "\nManager Details:" << endl;
    for(int i = 0; i < n; i++)
        m[i].display();

    int pos = 0;
    for(int i = 1; i < n; i++) {
        if(m[i].getSalary() > m[pos].getSalary())
            pos = i;
    }

    cout << "\nManager with Highest Salary:" << endl;
    cout << "Name: " << m[pos].getName() << endl;
    cout << "Salary: " << m[pos].getSalary() << endl;

    return 0;
}
