#include <iostream>
using namespace std;
class Employee{
	public:
		string firstName;
		string lastName;
		double monthlySalary;
		Employee(string firstName,string lastName,double Salary){
			this->firstName=firstName;
			this->lastName=lastName;
			this->monthlySalary=Salary;
		}
		void Raise(){
			this->monthlySalary=1.1*this->monthlySalary;
		}
};
int main(){
    Employee e1("Ghulam","Murtaza",30000);
    Employee e2("Yahya","Khan",1000);
    cout << "Employee 1 Yearly Salary : " << e1.monthlySalary * 12 << endl;
    cout << "Employee 2 Yearly Salary : " << e2.monthlySalary * 12 << endl;  
    e1.Raise();
    e2.Raise();
    cout << "Employee 1 Increased Yearly Salary : " << e1.monthlySalary * 12 << endl;
    cout << "Employee 2 Increased Yearly Salary : " << e2.monthlySalary * 12 << endl;  
	return 0;
}