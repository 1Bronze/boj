#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cnt = 0, time = 0;
    cin >> cnt;

    int *p = new int[cnt];

    for (int i = 0; i < cnt; i++)
        cin >> p[i];

    sort(p, p + cnt); // 오름차순 정렬

    for (int i = 0; i < cnt; i++) {
        /*
         * 1,2,3,4,5가 입력되었다면
         * 1는 5번, 2는 4번, 3은 3번, 4는 2번, 5는 1번 더해진다.
         */
        time += p[i] * (cnt - i);
    }

    cout << time;

    delete[] p;
}