#include <iostream>
#include <string>
using namespace std;

string s;
int stick[100000];
int result = 0;

int main() {
    
    stick[0] = 1;
    cin >> s;
    
    for(int i=1; i<s.length(); i++) {
        if(s[i]=='(') 
            stick[i] = stick[i-1] + 1;
        else
            stick[i] = stick[i-1] - 1;
    }
    
    for(int i=1; i<s.length(); i++) {
        if(s[i-1]=='(' && s[i]==')')
            result += stick[i];
        else if(s[i]==')')
            result += 1;
    }
    
    cout << result;
    return 0;
}