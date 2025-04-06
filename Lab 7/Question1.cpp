#include <iostream>
#include <algorithm>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) {
            cout << "Cannot create a fraction with denominator 0." << endl;
            exit(EXIT_FAILURE);
        }
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        int gcd = __gcd(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return (long long)numerator * other.denominator < (long long)other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.denominator == 1)
        os << f.numerator;
    else
        os << f.numerator << "/" << f.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    char slash;
    is >> f.numerator >> slash >> f.denominator;
    f.reduce();
    return is;
}

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << "f1: " << f1 << ", f2: " << f2 << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;
    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl;

    Fraction inputFrac;
    cout << "Enter a fraction (e.g., 3/4): ";
    cin >> inputFrac;
    cout << "You entered: " << inputFrac << endl;

    return 0;
}

