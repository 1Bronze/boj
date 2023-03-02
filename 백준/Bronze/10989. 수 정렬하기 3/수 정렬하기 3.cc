/**
 * 10989. 수 정렬하기 3
 */

#define MAX 10001

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 1; i < MAX; i++) {
        while(arr[i]--) cout << i << "\n";
    }

    return 0;
}