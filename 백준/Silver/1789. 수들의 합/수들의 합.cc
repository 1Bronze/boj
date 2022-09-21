/* 10 = 1+2+3+4 (4개)
 * 11 = 1+2+3+5 (4개)
 * 12 = 1+2+3+6 = 1+2+4+5 (4개)
 * 13 = 1+2+3+7 = 1+2+4+6 = 1+3+4+5 (4개)
 * 14 = 1+2+3+8 = 1+2+4+7 = 1+2+5+6 = 1+3+4+6 = 2+3+4+5 (4개)
 * 15 = 1+2+3+4+5 (5개)
 *
 * 10~14 -> 4
 * 15~20 -> 5
 * 21~27 -> 6
 * 28~35 -> 7
 */

#include <iostream>

long nSum(int cnt);

using namespace std;

int main() {
    long s; // 입력받은 값의 범위가 1 ≤ S ≤ 4,294,967,295 이므로 long으로 선언
    int cnt = 1;

    cin >> s;

    while (true) {
        long cntSum = nSum(cnt);

        if(s >= cntSum) {
            cnt++;
        } else {
            cout << cnt-1;
            break;
        }
    }
}

long nSum(int n) { // 1부터 n까지의 합을 구하는 함수
    long s = 0;

    for(int i = 1; i <= n; i++)
        s += i;

    return s;
}