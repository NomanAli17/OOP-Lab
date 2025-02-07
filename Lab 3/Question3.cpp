#include <iostream>
using namespace std;
class Glass{
	public:
		int LiquidLevel;
		Glass(){
			this->LiquidLevel=200;
		}
		void Drink(int Amount){
			this->LiquidLevel=this->LiquidLevel-Amount;
		}
		void Refill(){
			this->LiquidLevel=200;
		}
};
int main(){
	Glass Dinner;
	int choice=1;
	cout << "Enter 0 to End and 1 to Continue" << endl;
	cin >> choice;
	while(choice){
	    	cout << "Enter the Amount to Drink" << endl;
	    	int amount;
	    	cin >> amount;
	    	Dinner.Drink(amount);
	    	if(Dinner.LiquidLevel <= 100){
	    		Dinner.Refill();
			}
		    cout << "Enter 0 to End and 1 to Continue" << endl;
	        cin >> choice;		
	}
	return 0;
}