#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    // Prefix decrement: --obj
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix decrement: obj--
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n(8);

    cout << "Original: ";
    n.display();

    --n;
    cout << "After prefix -- (multiply by 4): ";
    n.display();

    n--;
    cout << "After postfix -- (divide by 4): ";
    n.display();

    return 0;
}

