#include <iostream>

using namespace std;
class Book{
	string book;
	int ISBN;
	string author;
	string publisher;
	public:
		void setDetails(string book,int ISBN,string author,string publisher){
			this->book=book;
			this->ISBN=ISBN;
			this->author=author;
			this->publisher=publisher;
		}
		void getBookInfo(){
			string space = " ";
			string result = this->book + space + to_string(this->ISBN) + space + this->author + space + this->publisher + space;
			cout << result << endl;
		}
};
int main(){
	Book b[5];
	for(int i=0;i<5;i++){
		string book;
		int ISBN;
		string author;
		string publisher;
		cout << "Enter Book Name. \n"; cin >> book;
		cout << "Enter ISBN. \n"; cin >> ISBN;
		cout << "Enter Author. \n"; cin >> author;
		cout << "Enter Publisher. \n"; cin >> publisher;
		b[i].setDetails(book,ISBN,author,publisher);
	}
	for(int i=0;i<5;i++){
		b[i].getBookInfo();
	}
	return 0;
}