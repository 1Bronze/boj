/**
* 11718. 그대로 출력하기
*/

#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        getline(cin, s);
        if(s.empty()) break;
        cout << s << "\n";
    }

    return 0;
}