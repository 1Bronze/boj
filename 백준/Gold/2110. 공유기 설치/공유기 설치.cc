/**
* 2110. 공유기 설치
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
int arr[200000];
int l, r, mid;
int result;

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    l = 0, r = arr[N - 1] - arr[0];
    while(l<=r) {
        mid = (l + r) / 2;

        int prevHouse = arr[0];
        int cnt = 1; // 0번째 집에 공유기 설치

        for (int i = 1; i < N; i++) {
            int nextHouse = arr[i];
            int distance = nextHouse - prevHouse;
            if(distance >= mid) {
                cnt++; // i번째 집에 공유기 설치
                prevHouse = nextHouse;
            }
        }

        if(cnt>=C) { // 공유기를 더 많이 설치한 경우 -> 간격(mid)을 늘린다.
            l = mid + 1;
            result = (result<mid) ? mid:result;
        } else { // 공유기를 더 적게 설치한 경우 -> 간격(mid)를 좁힌다.
            r = mid - 1;
        }
    }

    cout << result;
}