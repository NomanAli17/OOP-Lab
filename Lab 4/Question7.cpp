#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Book {
	private:
		string author;
		string title;
		double price;
		string publisher;
		int stock;
	public:
		Book(string auth,string tit,double pr,string pub,int st):author(auth),title(tit),price(pr),publisher(pub),stock(st) {}
		string getTitle()const {
			return title;
		}
		string getAuthor()const {
			return author;
		}
		bool isAvailable(int requestedCopies)const {
			return stock>=requestedCopies;
		}
		void reduceStock(int quantity) {
			stock-=quantity;
		}
		void printDetails()const {
			cout<<"Title: "<<title<<", Author: "<<author<<", Price: "<<price<<", Publisher: "<<publisher<<", Stock: "<<stock<<endl;
		}
		double getTotalPrice(int quantity)const {
			return price*quantity;
		}
};
class BookShop {
	private:
		vector<Book> inventory;
	public:
		void addBook(const Book& book) {
			inventory.push_back(book);
		}
		void searchBook(const string& title,const string& author,int requestedCopies) {
			for(auto& book:inventory) {
				if(book.getTitle()==title&&book.getAuthor()==author) {
					book.printDetails();
						if(book.isAvailable(requestedCopies)) {
						cout<<"Total cost: "<<book.getTotalPrice(requestedCopies)<<endl;
						book.reduceStock(requestedCopies);
					} else cout<<"Required copies not in stock."<<endl;
					return;
				}
			}
			cout<<"Book not found."<<endl;
		}
};
int main() {
	BookShop shop;
	shop.addBook(Book("Author1","Book1",15.0,"Publisher1",10));
	shop.searchBook("Book1","Author1",3);
	return 0;
}
