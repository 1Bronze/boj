#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[20000];

bool compare(string& s1, string& s2) {
    int len1 = s1.length(), len2 = s2.length();
    if(len1!=len2) return len1 < len2;
    else return s1 < s2;
}

int main() {
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];

    sort(arr, arr+N, compare);
    
    cout << arr[0] << "\n";
    for(int i=1; i<N; i++) {
        if(arr[i]==arr[i-1]) continue;
        cout << arr[i] << "\n";
    }
}