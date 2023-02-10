/**
* 10815. 숫자 카드
*/

#include <cstdio>
#include <algorithm>

int M, N, num, result;
int maxi = 0, mini = 0;
int arr[500000];

int main() {
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
    }

    std::sort(arr, arr+M);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        int l=0, r=M-1, mid;
        result = 0;

        while(l<=r) {
            mid = (l+r)/2;

            if(num>arr[mid]) {
                l = mid + 1;
            } else if(num<arr[mid]) {
                r = mid - 1;
            } else {
                result = 1;
                break;
            }
        }

        printf("%d ", result);
    }

}