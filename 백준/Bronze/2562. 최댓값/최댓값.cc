#include <iostream>
using namespace std;

int main() {
    int arr[10];
    
    for(int i=1; i<10; i++)
        cin >> arr[i];
    
    int max = arr[1];
    int idx = 1;
    for(int i=2; i<10; i++) {
        if(max<arr[i]) {
            max = arr[i];
            idx=i;
        }
    }
    
    cout << max << "\n" << idx;
    return 0;
}