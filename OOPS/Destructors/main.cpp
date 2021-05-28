// Program to demonstrate destructors

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

    // public methods
    void get_data() {
        cout << "Name: " << name << endl;
        cout << "Model: " << modelNo << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }

    // Destructors defined
    // Remember object created later is deleted first!
    ~Car() {
        cout << "Destroying objects:: " << name << endl;
        if (name != NULL)
            delete name;
    }
};

int main() {
    // object of a car (Constructor called)
    Car c("Audi", 1, 10000);

    c.get_data();

    return 0;
}

// can also just call delete keyword to delete dynamically allocated objects
// no need to to delete static allocated objects.
// Static -> Car c(100, 200, "BMW");
// Dynamic ->

/*
 * Car *e = new Car(100,200,"BMW");
 * delete e;
*/