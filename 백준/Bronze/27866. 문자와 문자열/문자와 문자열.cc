#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    int cnt;
    cin >> s;
    cin >> cnt;
    cout << s[cnt-1];
}