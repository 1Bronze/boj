/**
 * 14890. 경사로
 */

#include <iostream>
using namespace std;

int N, L, result;
int arr[101][101];

void checkRow() {

    for (int i=1; i<=N; i++) {
        bool flag = true;
        bool check[101];
        for (int j=1; j<=N; j++) check[j] = false;

        int cnt = 1;
        for (int j=2; j <= N; j++) {

            if(arr[i][j-1]==arr[i][j]) cnt++;
            else if(arr[i][j-1]<arr[i][j]) {

                if(arr[i][j]-arr[i][j-1]>1) {
                    flag = false;
                    break;
                }

                if(cnt<L) {
                    flag = false;
                    break;
                }
                for (int k=1; k<=L; k++) check[j-k] = true;
                cnt = 1;
            }
        }

        if(!flag) continue;

        cnt = 1;
        for (int j = N-1; j>=1; j--) {

            if(arr[i][j+1]==arr[i][j]) cnt++;
            else if(arr[i][j+1]<arr[i][j]) {

                if(arr[i][j]-arr[i][j+1]>1) {
                    flag = false;
                    break;
                }

                if(cnt<L) {
                    flag = false;
                    break;
                }
                for (int k=1; k<=L; k++) {
                    if(!check[j+k]) check[j+k] = true;
                    else flag = false;
                }
                cnt = 1;
                if(!flag) break;
            }
        }

        if(flag) {
//            cout << "row" << i << " ";
            result++;
//            cout << "\n";
        }
    }
}

void checkColumn() {

    for (int i=1; i<=N; i++) {
        bool flag = true;
        bool check[101];
        for (int j=1; j<=N; j++) check[j] = false;

        int cnt = 1;
        for (int j=2; j <= N; j++) {

            if(arr[j-1][i]==arr[j][i]) cnt++;
            else if(arr[j-1][i]<arr[j][i]) {
                if(arr[j][i]-arr[j-1][i]>1) {
                    flag = false;
                    break;
                }

                if(cnt<L) {
                    flag = false;
                    break;
                }
                for (int k=1; k<=L; k++) check[j-k] = true;
                cnt = 1;
            }
        }

        if(!flag) continue;

        cnt = 1;
        for (int j = N-1; j>=1; j--) {

            if(arr[j+1][i]==arr[j][i]) cnt++;
            else if(arr[j+1][i]<arr[j][i]) {
                if(arr[j][i]-arr[j+1][i]>1) {
                    flag = false;
                    break;
                }

                if(cnt<L) {
                    flag = false;
                    break;
                }
                for (int k=1; k<=L; k++) {
                    if(!check[j+k]) check[j+k] = true;
                    else flag = false;
                }
                cnt = 1;
                if(!flag) break;
            }
        }

        if(flag) {
//            cout << "column" << i << " ";
            result++;
//            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    checkRow();
    checkColumn();
    cout << result << "\n";
}