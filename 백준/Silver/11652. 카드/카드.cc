#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long arr[100000];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);

    sort(arr, arr + N);

    int cnt = 1, max = 1;
    long long cur = arr[0];
    long long ans = arr[0];

    for (int i = 1; i < N; i++) {
        if (cur == arr[i]) {
            cnt++;
            if (max < cnt) {
                max = cnt;
                ans = cur;
            }
        } else {
            if (max < cnt) {
                max = cnt;
                ans = cur;
            }
            cur = arr[i];
            cnt = 1;
        }
    }

    printf("%lld\n", ans);
}