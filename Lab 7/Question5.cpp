#include <iostream>
using namespace std;

class Shape {
private:
    double length;
    double width;

public:
    Shape(double l = 0, double w = 0) : length(l), width(w) {}

    double Area() const {
        return length * width;
    }

    Shape operator+(const Shape& other) {
        double totalArea = this->Area() + other.Area();
        return Shape(totalArea, 1);  
    }

    void displayArea() const {
        cout << "Area: " << Area() << endl;
    }
};

int main() {
    Shape shape1(5, 4); 
    Shape shape2(3, 6); 

    Shape result = shape1 + shape2;

    cout << "Shape1 ";
    shape1.displayArea();

    cout << "Shape2 ";
    shape2.displayArea();

    cout << "Total Area after shape1 + shape2: ";
    result.displayArea();

    return 0;
}

