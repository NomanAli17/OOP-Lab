#include <bits/stdc++.h>
using namespace std;
int main(int argc,char*  argv[]){
	if(argc<2){
		cout << "Array not Goiven";
		return 1;
	}
	int arr[argc-1];
	int size=argc-1;
	for(int i=0;i<size;i++){
		arr[i]=atoi(argv[i+1]);
	}
	int *ptr;
	ptr=arr;
	int sum=0;
	for(int i=0;i<size;i++){
		sum += *ptr;
		ptr++;
	}
	cout << sum;
	return 0;
}
