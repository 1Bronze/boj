#include <iostream>
#include <string>
using namespace std;

string str;
string result = "";

int CharToInt(char c) {
    return c - '0';
}

char intToChar(int i) {
    return i + '0';
}

int main() {
    cin >> str;
    int len = str.length();

    int tmp;
    if(len%3==0) {
        for(int i=0; i<len/3; i++) {
            tmp = 4*CharToInt(str[3*i]) + 2*CharToInt(str[3*i+1]) + CharToInt(str[3*i+2]);
            result.push_back(intToChar(tmp));
        }
    }
    else if(len%3==1) {
        result.push_back(intToChar(CharToInt(str[0])));
        for(int i=0; i<len/3; i++) {
            tmp = 4*CharToInt(str[3*i+1]) + 2*CharToInt(str[3*i+2]) + CharToInt(str[3*i+3]);
            result.push_back(intToChar(tmp));
        }
    }
    else {
        result.push_back(intToChar(2*CharToInt(str[0])+CharToInt(str[1])));
        for(int i=0; i<len/3; i++) {
            tmp = 4*CharToInt(str[3*i+2]) + 2*CharToInt(str[3*i+3]) + CharToInt(str[3*i+4]);
            result.push_back(intToChar(tmp));
        }
    }

    cout << result;
}