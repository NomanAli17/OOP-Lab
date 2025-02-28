#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Blend {
	public:
		void blendjuice() {
			cout<<"Blending fruit"<<endl;
			this_thread::sleep_for(chrono::seconds(4));
		}
};

class Grind {
	public:
		void grindjuice() {
			cout<<"Grinding juice"<<endl;
			this_thread::sleep_for(chrono::seconds(4));
		}

};

class Juicemaker {
		Blend b1;
		Grind g1;
	public:
		void makejuice() {
			b1.blendjuice();
			g1.grindjuice();
		}
};

int main() {
	Juicemaker j;
	j.makejuice();
	return 0;
}
