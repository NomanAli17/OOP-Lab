#include <iostream>
using namespace std;

class Vehicle {
public:
    int price;
    Vehicle(int p) : price(p) {}
};

class MotorCycle : public Vehicle {
public:
    int nGears;
    int nCylinders;
    int nWheels;
    MotorCycle(int p, int nG, int nC, int nW) : Vehicle(p), nGears(nG), nCylinders(nC), nWheels(nW) {}
};

class Yamaha : public MotorCycle {
public:
    string make;
    Yamaha(int p, int nG, int nC, int nW, string m) : MotorCycle(p, nG, nC, nW), make(m) {}
    void displayDetails() {
        cout << "Yamaha Motorcycle Details:\n";
        cout << "Price: " << price << endl;
        cout << "Number of Gears: " << nGears << endl;
        cout << "Number of Cylinders: " << nCylinders << endl;
        cout << "Number of Wheels: " << nWheels << endl;
        cout << "Make: " << make << endl;
    }
};

class Car : public Vehicle {
public:
    int capacity;
    int nDoors;
    string fType;
    Car(int p, int c, int nD, string fT) : Vehicle(p), capacity(c), nDoors(nD), fType(fT) {}
};

class Audi : public Car {
public:
    string model;
    Audi(int p, int c, int nD, string fT, string m) : Car(p, c, nD, fT), model(m) {}
    void displayDetail() {
        cout << "Audi Car Details:\n";
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of Doors: " << nDoors << endl;
        cout << "Fuel Type: " << fType << endl;
    }
};

int main() {
    Yamaha yamaha(15000, 6, 2, 2, "Yamaha R15");
    Audi audi(35000, 5, 4, "Petrol", "Audi A4");

    yamaha.displayDetails();
    audi.displayDetail();

    return 0;
}

