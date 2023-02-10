/**
* 2805. 나무 자르기
*/

#include <iostream>
using namespace std;

int N, M;
int arr[1000001];
int l = 0, r = 0, mid;
int result = 0;

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        r = (arr[i]>r) ? arr[i] : r;
    }

    while(l<=r) {
        mid = (l+r)/2;

        long long n = 0;
        for (int i = 1; i <= N; i++) {
            int tmp = arr[i] - mid;
            if(tmp>0) n+=tmp;
        }

        if(n>=M) { // 자른게 가져갈 것보다 많은 경우 -> 덜 잘라야 함.
            l = mid + 1;
            result = (result<mid) ? mid:result;
        } else {
            r = mid-1;
        }
    }

    cout << result;
}