#include<iostream>
#include<vector>
#include<string>
using namespace std;
class MenuItem {
	public:
		string name;
		string type;
		double price;
		MenuItem(string n,string t,double p):name(n),type(t),price(p) {}
};
class CoffeeShop {
	private:
		string name;
		vector<MenuItem> menu;
		vector<string> orders;
	public:
		CoffeeShop(string n):name(n) {}
		void addMenuItem(string name,string type,double price) {
			menu.push_back(MenuItem(name,type,price));
		}
		void addOrder(string itemName) {
			for(auto& item:menu) {
				if(item.name==itemName) {
					orders.push_back(itemName);
					return;
				}
			}
			cout<<"This item is currently unavailable"<<endl;
		}
		void fulfillOrder() {
			if(!orders.empty()) {
				cout<<"The "<<orders.front()<<" is ready"<<endl;
				orders.erase(orders.begin());
			} else cout<<"All orders have been fulfilled"<<endl;
		}
		void listOrders() {
			if(orders.empty())cout<<"No orders"<<endl;
			else {
				for(const auto& order:orders) {
					cout<<order<<endl;
				}
			}
		}
		double dueAmount() {
			double total=0;
			for(const auto& order:orders) {
				for(const auto& item:menu) {
					if(item.name==order) {
						total+=item.price;
						break;
					}
				}
			}
			return total;
		}
		string cheapestItem() {
			if(menu.empty())return "";
			MenuItem cheapest=menu[0];
			for(const auto& item:menu) {
				if(item.price<cheapest.price) {
					cheapest=item;
				}
			}
			return cheapest.name;
		}
		vector<string> drinksOnly() {
			vector<string> drinks;
			for(const auto& item:menu) {
				if(item.type=="drink") {
					drinks.push_back(item.name);
				}
			}
			return drinks;
		}
		vector<string> foodOnly() {
			vector<string> food;
			for(const auto& item:menu) {
				if(item.type=="food") {
					food.push_back(item.name);
				}
			}
			return food;
		}
};
int main() {
	CoffeeShop shop("Café de la Plaza");
	shop.addMenuItem("Latte","drink",3.5);
	shop.addMenuItem("Espresso","drink",2.0);
	shop.addMenuItem("Croissant","food",2.5);
	shop.addOrder("Latte");
	shop.addOrder("Croissant");
	shop.fulfillOrder();
	cout<<"Due Amount: $"<<shop.dueAmount()<<endl;
	cout<<"Cheapest Item: "<<shop.cheapestItem()<<endl;
	return 0;
}
