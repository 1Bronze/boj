#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;

int main() {
    cin >> s;
    
    for(int i=0; i<s.length(); i++) s[i] = toupper(s[i]);
    
    sort(s.begin(), s.end());
    
    int maxNum = 1; char maxChar = s[0];
    int cnt = 1;
    for(int i=1; i<s.length(); i++) {
        if(s[i]==s[i-1]) cnt++;
        else cnt = 1;
        
        if(cnt>maxNum) {
            maxNum = cnt;
            maxChar = s[i];
        } else if(cnt==maxNum) {
            maxChar = '?';
        }
    }
    
    cout << maxChar;
}