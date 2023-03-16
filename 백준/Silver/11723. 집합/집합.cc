#include <iostream>
#include <string>

using namespace std;

int N;
int BIT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        string str;
        int x;
        cin >> str;
        if (str == "add") {
            cin >> x;
            // n번째 bit를 1로 바꾼다. (or 연산이므로 다른 bits의 값은 당연히 변경되지 않는다.)
            BIT |= (1 << x);
        } else if (str == "remove") {
            cin >> x;
            // n번째 bit를 0으로 바꾼다. (~ 연산이므로 다른 값들은 1이 되어 &를 해도 유지된다.)
            BIT &= ~(1 << x);
        } else if (str == "check") {
            cin >> x;
            // n번째 bit가 1일 때 1을 출력한다. (다른 bit는 입력값이 0이므로 & 연산을 해도 무관하다.)
            if (BIT & (1 << x)) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (str == "toggle") {
            cin >> x;
            // BIT의 n번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // n번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
            BIT ^= (1 << x);
        } else if (str == "all") {
            BIT = (1 << 21) - 1;
        } else if (str == "empty") {
            BIT = 0;
        }
    }

    return 0;
}