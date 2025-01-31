#include <iostream>
#include <cstdio>
#include <cstdlib>  
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) { 
        cout << "Please provide your name and at least one number." << endl;
        return 1;
    }
    string name = argv[1];  
    int numCount = argc - 2;  
    float num[numCount];  
    for (int i = 0; i < numCount; i++) {
        num[i] = atof(argv[i + 2]);  
    }
    float sum = 0;
    for (int i = 0; i < numCount; i++) {
        sum += num[i];
    }
    float avg = sum / numCount;
    cout << name << " " << endl;
    printf("%.2f", avg);

    return 0;
}

