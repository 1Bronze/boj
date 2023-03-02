/**
 * 2231. 분해합
 */

#define MAX 1000000

#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i < MAX; i++) {
        int a,b,c,d,e,f;
        a = i/100000;
        b = (i%100000) / 10000;
        c = (i%10000) / 1000;
        d = (i%1000) / 100;
        e = (i%100) / 10;
        f = i % 10;

        if(i+a+b+c+d+e+f == N) {
            cout << i;
            break;
        }

        if(i == MAX-1)
            cout << 0;
    }

    return 0;
}