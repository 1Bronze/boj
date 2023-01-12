#include <iostream>
#include <string>
using namespace std;

int arr[8];
string status = "mixed";

int main() {
    for(int i=0; i<8; i++)
        cin >> arr[i];
    
    int target = arr[0];
    int D = 0;
    
    for(int i=1; i<8; i++) {
        if(target < arr[i]) { // 오름차순
            D++;
        } else if(target > arr[i]) { // 내림차순
            D--;
        }
        target = arr[i];        
    }
    
    if(D==7) status = "ascending";
    else if(D==-7) status = "descending";
    
    cout << status;
}