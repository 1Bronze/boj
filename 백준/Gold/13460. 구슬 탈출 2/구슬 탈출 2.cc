/**
 * 13460. 구슬 탈출 2
 */

#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10
int result = 11;

void input(int& N, int& M, char board[][MAX]) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

void up(const int& N, const int& M, char board[][MAX]) {
    for (int j = 1; j < M-1; j++) {
        for (int i = 2; i < N-1; i++) {
            int yPos = i, xPos = j;
            if(board[yPos][xPos]!='B' && board[yPos][xPos]!='R') continue;
            while(xPos>0 && xPos<M-1 && yPos>0 && yPos<N-1) {
                if(board[yPos-1][xPos]=='.') {
                    board[yPos-1][xPos] = board[yPos][xPos];
                    board[yPos][xPos] = '.';
                    yPos--;
                } else if(board[yPos-1][xPos]=='O') {
                    board[yPos][xPos] = '.';
                    break;
                } else {
                    break;
                }
            }
        }
    }
}

void down(const int& N, const int& M, char board[][MAX]) {
    for (int j = 1; j < M-1; j++) {
        for (int i = N-2; i > 0; i--) {
            int yPos = i, xPos = j;
            if(board[yPos][xPos]!='B' && board[yPos][xPos]!='R') continue;
            while(xPos>0 && xPos<M-1 && yPos>0 && yPos<N-1) {
                if(board[yPos+1][xPos]=='.') {
                    board[yPos+1][xPos] = board[yPos][xPos];
                    board[yPos][xPos] = '.';
                    yPos++;
                } else if(board[yPos+1][xPos]=='O') {
                    board[yPos][xPos] = '.';
                    break;
                } else {
                    break;
                }
            }
        }
    }
}

void left(const int& N, const int& M, char board[][MAX]) {
    for (int i = 1; i < N-1; i++) {
        for (int j = 2; j < M-1; j++) {
            int yPos = i, xPos = j;
            if(board[yPos][xPos]!='B' && board[yPos][xPos]!='R') continue;
            while(xPos>0 && xPos<M-1 && yPos>0 && yPos<N-1) {
                if(board[yPos][xPos-1]=='.') {
                    board[yPos][xPos-1] = board[yPos][xPos];
                    board[yPos][xPos] = '.';
                    xPos--;
                } else if(board[yPos][xPos-1]=='O') {
                    board[yPos][xPos] = '.';
                    break;
                } else {
                    break;
                }
            }
        }
    }
}

void right(const int& N, const int& M, char board[][MAX]) {
    for (int i = 1; i < N-1; i++) {
        for (int j = M-2; j > 0; j--) {
            int yPos = i, xPos = j;
            if(board[yPos][xPos]!='B' && board[yPos][xPos]!='R') continue;
            while(xPos>0 && xPos<M-1 && yPos>0 && yPos<N-1) {
                if(board[yPos][xPos+1]=='.') {
                    board[yPos][xPos+1] = board[yPos][xPos];
                    board[yPos][xPos] = '.';
                    xPos++;
                } else if(board[yPos][xPos+1]=='O') {
                    board[yPos][xPos] = '.';
                    break;
                } else {
                    break;
                }
            }
        }
    }
}

bool hasR(const int& N, const int& M, char board[][MAX]) {

    bool flag = false;
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            if(board[i][j]=='R') flag = true;
        }
    }
    return flag;
}

bool hasB(const int& N, const int& M, char board[][MAX]) {

    bool flag = false;
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            if(board[i][j]=='B') flag = true;
        }
    }
    return flag;
}

void copyBoard(const int& N, const int& M, char board[][MAX], char nextBoard[][MAX]) {
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            nextBoard[i][j] = board[i][j];
        }
    }
}

void dfs(const int& N, const int& M, char board[][MAX], const int& depth) {

    // base case
    if(!hasB(N, M, board) || depth>10) {
        if(result==11) result = -1;
        return;
    }
    if(!hasR(N, M, board)) {
        if(result==-1) result = depth;
        else result = min(result, depth);
        return;
    }

    char nextUpBoard[MAX][MAX];
    char nextDownBoard[MAX][MAX];
    char nextLeftBoard[MAX][MAX];
    char nextRightBoard[MAX][MAX];

    copyBoard(N, M, board, nextUpBoard);
    copyBoard(N, M, board, nextDownBoard);
    copyBoard(N, M, board, nextLeftBoard);
    copyBoard(N, M, board, nextRightBoard);

    up(N, M, nextUpBoard);
    down(N, M, nextDownBoard);
    left(N, M, nextLeftBoard);
    right(N, M, nextRightBoard);

    dfs(N, M, nextUpBoard, depth+1);
    dfs(N, M, nextDownBoard, depth+1);
    dfs(N, M, nextLeftBoard, depth+1);
    dfs(N, M, nextRightBoard, depth+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    char board[MAX][MAX];

    input(N, M, board);
    dfs(N, M, board, 0);
    cout << result << "\n";
}