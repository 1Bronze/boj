/**
 * 2292. 벌집
 *
 * 1 6 12 18 24 ...
 */

#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if(N==1) {
        cout << 1;
        return 0;
    }

    int n = 6, cnt = 2;
    while(1) {
        N -= n;
        if(N<=1) break;
        n += 6;
        cnt++;
    }

    cout << cnt;
    return 0;
}