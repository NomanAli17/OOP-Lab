#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc,char* argv[]){
	if (argc < 2) {
        cout << "Please provide at least one number as argument." << endl;
        return 1;
    }
	int arr[argc-1];
	for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]); 
    }
	int size=argc-1;
	int sum=0;
	int *ptr=arr;
	for(int i=0;i<size;i++){
		sum += *(arr+i);
	}
	cout<<"The Sum is " << sum << endl;
	return 0;
}
