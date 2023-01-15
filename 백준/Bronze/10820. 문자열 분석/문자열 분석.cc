#include <iostream>
#include <string>
using namespace std;

#define lower 0
#define upper 1
#define number 2
#define space 3

int num[4];
string s;

int main() {
    while(1) {
        getline(cin, s);
        if(cin.eof()) break;

        for(int i=0; i<4; i++) num[i] = 0;

        for(int i=0; i<s.length(); i++) {
            if(int(s[i])==32) num[space]++;
            else if(int(s[i])>=48 && int(s[i])<=57) num[number]++;
            else if(int(s[i])>=65 && int(s[i])<=90) num[upper]++;
            else if(int(s[i])>=97 && int(s[i])<=122) num[lower]++;
        }

        for(int i=0; i<4; i++) cout << num[i] << " ";
        cout << "\n";
    }

    return 0;
}