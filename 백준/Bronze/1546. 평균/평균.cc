#include <iostream>
using namespace std;

int main() {
    int num;
    double highscore, mean;
    
    cin >> num;
    
    double* arr = new double[num];
    
    for(size_t i = 0; i < num; i++) {
        cin >> arr[i];
    }
    
    highscore = arr[0];
    
    for(size_t i = 0; i < num; i++) {
        if(highscore < arr[i])
            highscore = arr[i];
    }
    
    for(size_t i = 0; i < num; i++) {
        arr[i] = arr[i] / highscore * 100;
        mean += arr[i];
    }
    
    mean /= num;
    
    cout << mean;
    
    delete[] arr;
}