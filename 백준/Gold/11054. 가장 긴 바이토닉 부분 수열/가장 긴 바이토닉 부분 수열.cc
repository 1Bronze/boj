/**
 * 11054. 가장 긴 바이토닉 부분 수열
 */

#define MAX 1001

#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int arr[MAX];
int increase[MAX], decrease[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        increase[i] = 1;

        for (int j = i-1; j >= 1; j--) {
            if(arr[i]>arr[j])
                increase[i] = max(increase[i], increase[j]+1);
        }
    }

    for (int i = N; i >= 1; i--) {
        decrease[i] = 1;

        for (int j = i+1; j <= N; j++) {
            if(arr[i]>arr[j])
                decrease[i] = max(decrease[i], decrease[j]+1);
        }
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, increase[i]+decrease[i]-1);

    cout << ans;
}