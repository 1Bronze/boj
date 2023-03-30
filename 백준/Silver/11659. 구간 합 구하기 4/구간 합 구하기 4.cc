/**
 * 11659. 구간 합 구하기 4
 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int arr[100001];
    int sum[100001];
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for (int i = 1; i <= M; i++) {
        int from, to;
        cin >> from >> to;
        
        cout << sum[to] - sum[from-1] << "\n";
    }

    return 0;
}