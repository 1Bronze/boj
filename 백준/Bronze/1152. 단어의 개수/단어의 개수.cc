#include <iostream>
using namespace std;

string s; int num = 1;

int main() {
    getline(cin, s);
    
    for(int i=0; i<s.length()-1; i++)
        if(s[i]==' ') num ++;
        
    if(s[0]==' ') num--;
    if (s[s.length()]==' ') num--;
    
    cout << num;
    
    return 0;
}