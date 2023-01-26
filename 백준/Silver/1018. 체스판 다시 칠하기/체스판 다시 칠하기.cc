#include <iostream>
using namespace std;

char board[50][50];

int getMinSquares(int r, int c) {
    int n1 = 0, n2 = 0;

    for(int i=0; i<=7; i++) {
        for(int j=0; j<=7; j++) {
            if((r+i+c+j)%2==0 && board[r+i][c+j]=='B') n1++;
            if((r+i+c+j)%2==1 && board[r+i][c+j]=='W') n1++;
            if((r+i+c+j)%2==0 && board[r+i][c+j]=='W') n2++;
            if((r+i+c+j)%2==1 && board[r+i][c+j]=='B') n2++;
        }
    }

    return (n1<n2) ? n1:n2;
}

int min(int a, int b) {
    return a<b ? a:b;
}

int main() {
    int m, n; cin >> m >> n;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int result = 100;
    for(int i=0; i<m-7; i++) {
        for(int j=0; j<n-7; j++) {
            result = min(result, getMinSquares(i, j));
        }
    }

    cout << result;
}