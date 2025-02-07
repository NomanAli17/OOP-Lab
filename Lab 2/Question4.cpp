#include <bits/stdc++.h>
using namespace std;
struct Employee{
	int id;
	string name;
	float salary=0;
};
struct Organization{
	int size;
	string name;
	int number;
	Employee emp;
};
int main(){
	Organization org;
	Employee emp;
	cin >> org.size;
	cin >> org.number;
	cin >> org.name;
	cin >> org.emp.id;
	cin >> org.emp.name;
	cin >> org.emp.salary;
	
	cout << "The Size of Structure Organization : " << org.size << endl;
	cout << "Organization Name : " << org.name << endl;
	cout << "Organization Number : " << org.number << endl;
	cout << "Employee Id : " << org.emp.id << endl;
	cout << "Employee Name : " << org.emp.name << endl;
	cout << "Employee Salary : " << org.emp.salary << endl;
	return 0;
}
