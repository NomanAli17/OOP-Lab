#include <iostream>
using namespace std;

class Car {
	public:
		mutable int engine; 
		mutable int horsepower;
		mutable int seating_capacity;
		mutable int no_of_speakers;

		Car(int e, int hp, int sc, int ns) : engine(e), horsepower(hp), seating_capacity(sc), no_of_speakers(ns) {}

		void display() const {
			cout << "Engine: " << engine << endl;
			cout << "Horsepower: " << horsepower << endl;
			cout << "Seating Capacity: " << seating_capacity << endl;
			cout << "Number of Speakers: " << no_of_speakers << endl;
		}

		void modifyAttributes(int e, int hp, int sc, int ns) const {
			engine = e;
			horsepower = hp;
			seating_capacity = sc;
			no_of_speakers = ns;
		}
};

int main() {
	Car myCar(1500, 120, 5, 4);
	cout << "Before Modification:" << endl;
	myCar.display();

	myCar.modifyAttributes(1800, 150, 7, 6);

	cout << "\nAfter Modification:" << endl;
	myCar.display();

	return 0;
}
