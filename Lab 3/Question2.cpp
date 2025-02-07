#include <iostream>
using namespace std;
class Date{
	public:
		int month;
	    int date;
	    int year;
	    void displayDate(){
	    	cout << this->date << "/" << this->month << "/" << this->year;
		}
};
int main(){
	Date DateTest;
	DateTest.month=12;
	DateTest.date=31;
	DateTest.year=2025;
	DateTest.displayDate();
	return 0;
}