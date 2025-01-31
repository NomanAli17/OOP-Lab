#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <iomanip>
using namespace std;
void roundOff(float weight,int decPlaces){
	cout << fixed ;
	cout << setprecision(decPlaces);
	cout << weight << endl;
}
int main(int argc,char* argv[]){
	if(argc<2){
        cout <<"Please provide at least one number as argument."<< endl;
        return 1;
    }
	float wkg=atof(argv[1]);
	scanf("%f",&wkg);
	float wpnd = wkg * 2.2;
	roundOff(wkg,2);
	roundOff(wpnd,2);
	return 0;
}
