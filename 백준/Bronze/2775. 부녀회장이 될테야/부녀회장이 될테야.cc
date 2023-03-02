/**
 * 2775. 부녀회장이 될테야
 */

#include <iostream>
using namespace std;

int T, k, n;
int arr[15][15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 14; i++) arr[0][i] = i;

    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            for (int l = 1; l <= j; l++) {
                arr[i][j] += arr[i-1][l];
            }
        }
    }

    cin >> T;
    while (T--) {
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }

    return 0;
}