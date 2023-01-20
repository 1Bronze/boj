#include <iostream>
#include <string>
using namespace std;

string str;
string result = "";

int main() {
    cin >> str;
    
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='0') result += "000";
        if(str[i]=='1') result += "001";
        if(str[i]=='2') result += "010";
        if(str[i]=='3') result += "011";
        if(str[i]=='4') result += "100";
        if(str[i]=='5') result += "101";
        if(str[i]=='6') result += "110";
        if(str[i]=='7') result += "111";
    }
    
    while(1) {
        if(result[0]=='0') result.erase(0, 1);
        else break;
    }
    
    if (result.length()!=0) cout << result;
    else cout << 0;
}