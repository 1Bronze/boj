/**
 * 2630. 색종이 만들기
 */

#define MAX 128

#include <iostream>
using namespace std;

int N;
int arr[MAX][MAX];
int white, blue;

void cut(int y, int x, int len) {
    bool flag = false;
    int first = arr[y][x];
    for (int i = y; i < y+len; i++) {
        for (int j = x; j < x+len; j++) {
            if(first!=arr[i][j]) flag = true;
        }
    }

    if(flag) {
        cut(y, x, len/2);
        cut(y+len/2, x, len/2);
        cut(y, x+len/2, len/2);
        cut(y+len/2, x+len/2, len/2);
    }
    else {
        if(first==0) white++;
        else blue++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cut(0, 0, N);
    cout << white << "\n" << blue;
}