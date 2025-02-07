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
		}
		matrix.resize(rows,vector<int>(columns));
		int getRows(){
			return rows;
		}
		int getColumns(){
			return columns;
		}
		void setElements(int element,int i,int j){
			matrix[i][j]=element;
		}	
};
int main(){
	Matrix m1(2,2);
	for(int i=0; i < m1.getRows(); i++){
		for(int j=0; j < m1.getColumns(); j++){
			int element;
			cin >> element;
			m1.setElements(element,i,j);
		}
	}
	return 0;
}