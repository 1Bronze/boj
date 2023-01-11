#include <cstdio>
#include <algorithm>

using namespace std;

int N; int K;
int arr[5000000];

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + N);

    printf("%d\n", arr[K-1]);

    return 0;
}