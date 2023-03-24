/**
 * 6064. 카잉 달력
 *
 * 3 13 23 33 43 ...
 * 9 21 33 45 ...
 */

#include <iostream>
using namespace std;

int T, M, N, x, y;

int getGCD(int a, int b) {
    int mod = a % b;

    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int getLCM(int a, int b) {
    return a * b / getGCD(a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> M >> N >> x >> y;
        int end = getLCM(M,N);

        while(1) {

            if(x>end || y>end) {
                cout << "-1\n";
                break;
            }

            if(x<y) x+=M;
            else if(x>y) y+=N;
            else {
                cout << x << "\n";
                break;
            }
        }
    }
}