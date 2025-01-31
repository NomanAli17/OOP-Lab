#include <iostream>
#include <cstdlib> 
using namespace std;

float secHigh(float* arr, int size){
    float highest = arr[0];
    float secHigh = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > highest) {
            secHigh = highest;
            highest = arr[i];
        } else if (arr[i] > secHigh && arr[i] != highest) {
            secHigh = arr[i];
        }
    }
    return secHigh;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide at least one number as argument." << endl;
        return 1;
    }

    float arr[argc - 1];  
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atof(argv[i]); 
    }

    int size = argc - 1; 
    float result = secHigh(arr, size);
    cout << "Second highest value: " << result << endl;

    return 0;
}

