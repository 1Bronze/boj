#include <iostream>
using namespace std;

bool isChecked[6][6];
int board[6][6];

bool checkRow(int y, int x) {
    int leftCnt = 0;
    int rightCnt = 0;

    int nx = x;
    while(nx > 1) {
        nx--;
        if(isChecked[y][nx]) leftCnt++;
        else break;
    }

    nx = x;
    while(nx < 5) {
        nx++;
        if(isChecked[y][nx]) rightCnt++;
        else break;
    }

    if(leftCnt+rightCnt == 4) return true;
    else return false;
}

bool checkColumn(int y, int x) {
    int upCnt = 0;
    int downCnt = 0;

    int ny = y;
    while(ny > 1) {
        ny--;
        if(isChecked[ny][x]) upCnt++;
        else break;
    }

    ny = y;
    while(ny < 5) {
        ny++;
        if(isChecked[ny][x]) downCnt++;
        else break;
    }

    if(upCnt+downCnt == 4) return true;
    else return false;
}

bool checkRightDiagonal(int y, int x) {
    int upLeftCnt = 0;
    int downRightCnt = 0;

    int ny = y;
    int nx = x;
    while(ny > 1 && nx > 1) {
        ny--; nx--;
        if(isChecked[ny][nx]) upLeftCnt++;
        else break;
    }

    ny = y; nx = x;
    while(nx < 5 && ny < 5) {
        ny++; nx++;
        if(isChecked[ny][nx]) downRightCnt++;
        else break;
    }

    if(upLeftCnt+downRightCnt == 4) return true;
    else return false;
}

bool checkLeftDiagonal(int y, int x) {
    int upRightCnt = 0;
    int downLeftCnt = 0;

    int ny = y;
    int nx = x;
    while(ny > 1 && nx < 5) {
        ny--; nx++;
        if(isChecked[ny][nx]) upRightCnt++;
        else break;
    }

    ny = y; nx = x;
    while(nx > 1 && ny < 5) {
        ny++; nx--;
        if(isChecked[ny][nx]) downLeftCnt++;
        else break;
    }

    if(upRightCnt+downLeftCnt == 4) return true;
    else return false;
}

int main() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <=5; j++) {
            cin >> board[i][j];
        }
    }

    int bingo = 0, ans = 0;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <=5; j++) {
            if(bingo >= 3) {
                cout << ans;
                return 0;
            }
            int tmp;
            cin >> tmp;
            ans++;
            for(int k = 1; k <= 5; k++) {
                for(int l = 1; l <=5; l++) {
                    if(board[k][l]==tmp) {
                        isChecked[k][l] = true;
                        if(checkRow(k,l)) bingo++;
                        if(checkColumn(k,l)) bingo++;
                        if(checkRightDiagonal(k,l)) bingo++;
                        if(checkLeftDiagonal(k,l)) bingo++;
                    }
                }
            }
        }
    }
}