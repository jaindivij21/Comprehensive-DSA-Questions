// Program to demonstrate difference bw shallow and deep copy constructor

#include<iostream>
#include<cstring>

using namespace std;

class Car {
// Private attributes: Can be accessed only by the class itself. By default the attributes are private
private:
    float price;
// Public attributes: Can be accessed outside the class
public:
    char *name; // pointer (causes problems in copy constructor)
    int modelNo;

    // parameterized constructor
    Car(char *n, int model, float p) {
        name = new char[strlen(n) + 1]; // name pointer points to an dynamic char array (i.e string)
        strcpy(name, n);    // set name as the parameter
        modelNo = model;
        price = p;
    }

    // COPY CONSTRUCTOR (Deep Copy)
    Car(Car &temp) {
        modelNo = temp.modelNo;
        price = 500;
        // change in name
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
    }

    // public methods
    void get_data() {
        cout << "Name: " << name << endl;
        cout << "Model: " << modelNo << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
};

int main() {
    // object of a car
    Car c("Audi", 1, 10000);  // Other constructor called

    // new object
    Car e(c);   // copy constructor - therefore copies the c object to e

    // any changes to name changes the names of both c and e objects

    // but since we used the deep copy, it'll be fine
    e.name[0] = 'B';
    c.get_data();
    e.get_data();


    return 0;
}