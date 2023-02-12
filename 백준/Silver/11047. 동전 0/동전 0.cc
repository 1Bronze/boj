/**
* 11047. 동전 0
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[10];
int cnt = 0;

bool compare(int a, int b) {
    return (a>b) ? true:false;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N, compare);

    for (int i = 0; i < N; i++) {
        if(K>=arr[i]) {
            int tmp = 0;
            tmp += K/arr[i];
            K -= tmp*arr[i];
            cnt += tmp;
        }
    }

    cout << cnt;
}