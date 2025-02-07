#include <iostream>
using namespace std;
class User{
	public:
		int age;
	    string name;
	    User(int age,string name){
	    	this->age=age;
	    	this->name=name;
		}
};
int main(){
	User u1(24,"Teo");
	cout << "My Name is " << u1.name << " and I'm " << u1.age << " years old.";
	return 0;
}
