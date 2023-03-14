/**
 * 10820. 문자열 분석
 */

#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        getline(cin, str);
        if(cin.eof()) break;

        int space, upper, lower, number;
        space = upper = lower = number = 0;
        for (int i = 0; i < str.length(); i++) {
            int t = (int)str[i];
            if(t==32) space++;
            else if(t>=65 && t<91) upper++;
            else if(t>=97 && t<123) lower++;
            else if(t>=48 && t<58) number++;
        }

        cout << lower << " " << upper << " " << number << " " << space << "\n";
    }

    return 0;
}