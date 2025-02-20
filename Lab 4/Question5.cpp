#include<iostream>
using namespace std;
class Account {
	private:
		double balance;
	public:
		Account(double initialBalance):balance(initialBalance) {}
		void credit(double amount) {
			balance+=amount;
		}
		void debit(double amount) {
			if(amount<=balance)balance-=amount;
			else cout<<"Insufficient balance!"<<endl;
		}
		double getBalance()const {
			return balance;
		}
};
int main() {
	Account acc(1000);
	acc.credit(500);
	acc.debit(300);
	cout<<"Current Balance: "<<acc.getBalance()<<endl;
	return 0;
}
