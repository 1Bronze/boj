#include <iostream>
#include <algorithm>
using namespace std;

int num[10];

int main() {
    for(int i=0; i<10; i++) {
        cin >> num[i];
        num[i] %= 42;
    }
    
    sort(num, num+10);
    
    int count = 1;
    for(int i=1; i<10; i++) {
        if(num[i-1]!=num[i]) count++;
    }
    
    cout << count;
}