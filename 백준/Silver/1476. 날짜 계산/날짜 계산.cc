/**
* 1476. 날짜 계산
 *
 * E -> E+15a
 * S -> S+28b  ==> res
 * M -> M+19c
 *
 * (res-E)%15 = 0
 * (res-S)%28 = 0
 * (res-M)%19 = 0
*/

#include <iostream>
using namespace std;

int E, S, M, res=1;

int main() {
    cin >> E >> S >> M;

    while(1) {
        int e = (res-E)%15;
        int s = (res-S)%28;
        int m = (res-M)%19;

        if(e==0 && s==0 && m==0) break;
        else res++;
    }

    cout << res;
}