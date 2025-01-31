#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>  
using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 4) {
        cout << "Too few arguments." << endl;
        return 1;
    }

    int customerId = atoi(argv[1]); 
    string name = argv[2];          
    int units = atoi(argv[3]);       
    if(units < 0) {
        cout << "Invalid Units." << endl;
        return 1;
    }
    float bill = 0;
    if(units < 200) {
        bill = units * 16.20;
    } else if(units >= 200 && units < 300) {
        bill = units * 20.10;
    } else if(units >= 300 && units < 500) {
        bill = units * 27.10;
    } else {
        bill = units * 35.90;
    }

    float surcharge = 0;
    if(bill > 18000) {
        surcharge = bill * 0.15; 
    }

    float netAmount = bill + surcharge;

    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges @Rs. 35.90 per unit: " << fixed << setprecision(2) << bill << endl;
    cout << "Surcharge Amount: " << fixed << setprecision(2) << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << fixed << setprecision(2) << netAmount << endl;

    return 0;
}

