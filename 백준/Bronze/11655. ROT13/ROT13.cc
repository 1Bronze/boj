#include <iostream>
#include <string>
using namespace std;

string s;

bool isUpper(char c) {
    if(int(c)>=65 && int(c)<=90) return true;
    else return false;
}

bool isLower(char c) {
    if(int(c)>=97 && int(c)<=122) return true;
    else return false;
}

int main() {
    getline(cin, s);
    
    for(int i=0; i<s.length(); i++) {
        if(isUpper(s[i])) {
            if(isUpper(char(int(s[i])+13))) cout << char(int(s[i])+13);
            else cout << char(int(s[i])+13-26);
        } else if(isLower(s[i])) {
            if(isLower(char(int(s[i])+13))) cout << char(int(s[i])+13);
            else cout << char(int(s[i])+13-26);
        } else {
            cout << s[i];
        }
    }
    
    return 0;
}