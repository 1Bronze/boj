#include <iostream>
using namespace std;

int N, M;
int arr[10000];
int result;

void search(int len) {
    int start = 0, end = start + len - 1;
    int sum = 0;

    for (int i = start; i <= end; i++) sum+=arr[i];
    if(sum==M) result++;

    while(end<N-1) {
        start++; end++;
        sum = sum - arr[start-1] + arr[end];
        if(sum==M) result++;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) search(i);

    cout << result;
}