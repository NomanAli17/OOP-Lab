#include <bits/stdc++.h>
using namespace std;
class Matrix{
	public:
		int rows;
		int columns;
		vector <vector<int>> matrix;
		Matrix(int rows,int columns){
			this->rows=rows;
			this->columns=columns;
			matrix.resize(rows,vector<int>(columns));
		}
		int getRows(){
			return rows;
		}
		int getColumns(){
			return columns;
		}
		void setElements(int element,int i,int j){
			matrix[i][j]=element;
		}
		int getElement(int i,int j){
			return matrix[i][j];
		}
};
void addition(Matrix &obj1,Matrix &obj2){
	if((obj1.getRows()==obj2.getRows())&&(obj1.getColumns()==obj2.getColumns())){
		Matrix obj3(obj1.getRows(),obj1.getColumns());
		for(int i=0;i<obj1.getRows();i++){
			for(int j=0;j<obj1.getColumns();j++){
			    obj3.setElements(obj1.getElement(i,j)+obj2.getElement(i,j),i,j);
			}
		}
		cout<<"Result of addition:"<<endl;
		for(int i=0;i<obj3.getRows();i++){
			for(int j=0;j<obj3.getColumns();j++){
				cout<<obj3.getElement(i,j)<<" ";
			}
			cout<<endl;
		}
	}else{
		cout << "The Matrix cannot be added." << endl;
	}
}
void multiplication(Matrix &obj1,Matrix &obj2){
	if(obj1.getColumns()==obj2.getRows()){
		Matrix obj3(obj1.getRows(),obj2.getColumns());
		for(int i=0;i<obj1.getRows();i++){
			for(int j=0;j<obj2.getColumns();j++){
				int sum=0;
				for(int k=0;k<obj1.getColumns();k++){
					sum+=obj1.getElement(i,k)*obj2.getElement(k,j);
				}
				obj3.setElements(sum,i,j);
			}
		}
		cout<<"Result of multiplication:"<<endl;
		for(int i=0;i<obj3.getRows();i++){
			for(int j=0;j<obj3.getColumns();j++){
				cout<<obj3.getElement(i,j)<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<"The Matrix cannot be multiplied."<<endl;
	}
}
int main(){
	Matrix m1(3,2);
	Matrix m2(2,2);
	cout << "Enter Elements of Matrix 1 :" <<endl;
	for(int i=0; i < m1.getRows(); i++){
		for(int j=0; j < m1.getColumns(); j++){
			int element;
			cin >> element;
			m1.setElements(element,i,j);
		}
	}
	cout << "Enter Elements of Matrix 2 :" <<endl;
	for(int i=0; i < m2.getRows(); i++){
		for(int j=0; j < m2.getColumns(); j++){
			int element;
			cin >> element;
			m2.setElements(element,i,j);
		}
	}
	addition(m1,m2);
	multiplication(m1,m2);
	return 0;
}
