#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[1000];

int main() {
    cin >> arr[0];

    for(int i=1; i<arr[0].length(); i++)
        arr[i] = arr[i-1].substr(1);

    sort(arr, arr+arr[0].length());
    for(string& str : arr) {
        if(str == "\0") break;
            cout << str << "\n";
    }
}