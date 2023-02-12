/**
* 10610. 30
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000];
int sum = 0;
bool hasZero = false;

bool compare(int a, int b) {
    return (a>b) ? true:false;
}

int main() {
    char c;
    int val, i = 0;

    while(1) {
        scanf("%c", &c);
        if(c=='\n') break;
        else val = c - '0';

        arr[i++] = val;
        sum += val;
        if(val == 0) hasZero = true;
    }

    sort(arr, arr+i, compare);

    if(sum%3==0 && hasZero)
        for (int j = 0; j < i; j++) cout << arr[j];
    else cout << -1;


}