/**
 * 2011. 암호코드
 */

#include <iostream>
#include <string>
using namespace std;

string code;
int DP[5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> code;

    if(code[0] == '0') {
        cout << 0;
        return 0;
    }
    else DP[0] = 1;

    // 입력이 한 자리 수인 경우
    if(code.length()==1) {
        cout << DP[0];
        return 0;
    }

    // 두 자리 이상의 입력이 들어온 경우
    int num = 10*(code[0]-'0') + (code[1]-'0');

    if(num>0 && num<=26) {
        if(num%10!=0) DP[1] = 2;
        else DP[1] = 1;
    } else {
        if(num%10!=0) DP[1] = 1;
        else {
            cout << 0;
            return 0;
        }
    }

    for (int i = 2; i < code.length(); i++) {

        num = 10*(code[i-1]-'0') + (code[i]-'0');

        if(num==0) {
            cout << 0;
            return 0;
        }

        // 두 자리 숫자 계산
        if(num>0 && num<=26 && code[i-1]!='0') DP[i] += DP[i-2];

        // 한 자리 숫자 계산
        if(code[i] != '0') DP[i] += DP[i-1];

        DP[i] %= 1000000;
    }

    cout << DP[code.length()-1];
    return 0;
}