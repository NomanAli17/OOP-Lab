#include <iostream>
#include <vector>
using namespace std;
class Engine {
		bool isRunning;
	public:
		Engine(){
			cout << "Car and Engine constructer " << endl;
		}
		void start() {
			cout << "Engine Started " << endl;
			isRunning=true;
		}
		void  stop() {
			cout << "Engine Stopped " << endl;
			isRunning=false;
		}
		~Engine(){
			cout << "Car and Engine destroyed " << endl;
		}
};
class Car {
	private:
		Engine engine;
	public:
		Car(){
			//No need as engine already has constructor 
		}
		void startCar() {
			engine.start();
		}
		void stopCar() {
			engine.stop();
		}
		~Car(){
			//No need as engine already has destructor 
		}
};

int main() {
    Car c1;
    c1.startCar();
    c1.stopCar();
	return 0;
}