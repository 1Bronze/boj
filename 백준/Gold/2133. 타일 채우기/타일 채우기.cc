/**
 * 2133. 타일 채우기
 */

#include <iostream>
using namespace std;

int N;
int DP[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DP[2] = 3;

    for (int i = 4; i <= 30; i+=2) {
        DP[i] = 2;

        for (int j = 2; j < i; j+=2) {
            if(j==i-2) DP[i] += 3 * DP[j];
            else DP[i] += 2 * DP[j];
        }
    }


    cout << DP[N];
}