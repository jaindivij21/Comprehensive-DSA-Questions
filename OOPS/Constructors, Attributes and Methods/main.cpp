// Program to demonstrate making of a class, attributes, methods and constructors

#include<iostream>

using namespace std;

class Car {
// Private attributes: Can be accessed only by the class itself. By default the attributes are private
private:
    float price;
// Public attributes: Can be accessed outside the class
public:
    string name;
    int modelNo;

    // constructor overloading
    // default constructor (has the same name as the class name)
    Car() {
        cout << "Car class constructor called" << endl;
    }

    // parameterized constructor
    Car(string n, int model, float p) {
        name = n;
        modelNo = model;
        price = p;
    }

    // public methods
    void set_price(float p) {
        price = p;
    }

    void get_data() {
        cout << "Name: " << name << endl;
        cout << "Model: " << modelNo << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
};

int main() {
    // object of a car
    Car c; // Default Constructor called
    Car d("Audi", 002, 10000);  // Other constructor called

    c.name = "Ford Ecosport";
    c.modelNo = 001;
    //  c.price = 12345; // can't be called cuz its private
    // so to set the price use the public method
    c.set_price(12345);

    c.get_data();
    d.get_data();

    return 0;
}