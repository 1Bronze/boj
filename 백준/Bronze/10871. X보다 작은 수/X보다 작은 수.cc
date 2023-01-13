#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    
    int arr[10000];
    int n, threshold;
    cin >> n >> threshold;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
        if(arr[i]<threshold) cout << arr[i] << " ";
    }
}