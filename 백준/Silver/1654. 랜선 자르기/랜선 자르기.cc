/**
* 1654. 랜선 자르기
 *
 * K개의 랜선을 잘라서 N개의 랜선 만들기
 * K개의 랜선 길이가 차례로 주어짐.
*/

#include <iostream>
using namespace std;

int K, N;
long long result;
long long wire[10001];

int main() {
    cin >> K >> N;

    long long l = 1, r = 0;
    for (int i = 1; i <= K; i++) {
        cin >> wire[i];
        if (r < wire[i]) r = wire[i];
    }

    while(l<=r) {

        long long cnt = 0;
        long long mid = (l+r)/2;

        for (int i = 1; i <= K; i++)
            cnt += wire[i] / mid;

        if (cnt >= N) {
            l = mid + 1;
            result = (result<mid) ? mid:result;
        } else if (cnt < N) {
            r = mid - 1;
        }
    }

    cout << result;
}