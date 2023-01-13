#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int year;
    bool isLeap = false;
    
    cin >> year;
    
    if(year%4==0) {
        isLeap = true;
    }
    if(year%100==0) {
        isLeap = false;
    }
    if(year%400==0) {
        isLeap = true;
    }
    
    if(isLeap) cout << 1;
    else cout << 0;
}