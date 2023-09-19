#define EMPTY 0
#define BLACK 1
#define WHITE 2

#include<iostream>
using namespace std;

int N;
int board[101][101];

int countLeft(int y, int x, int color) {
    int ret = 0;
    while(x>1) {
        x -= 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countRight(int y, int x, int color) {
    int ret = 0;
    while(x<N) {
        x += 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countUp(int y, int x, int color) {
    int ret = 0;
    while(y>1) {
        y -= 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countDown(int y, int x, int color) {
    int ret = 0;
    while(y<N) {
        y += 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countLeftUp(int y, int x, int color) {
    int ret = 0;
    while(y>1 && x>1) {
        y -= 1; x -= 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countRightDown(int y, int x, int color) {
    int ret = 0;
    while(y<N && x<N) {
        y += 1; x += 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countRightUp(int y, int x, int color) {
    int ret = 0;
    while(y>1 && x<N) {
        y -= 1; x += 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

int countLeftDown(int y, int x, int color) {
    int ret = 0;
    while(y<N && x>1) {
        y += 1; x -= 1;
        if(board[y][x]==BLACK && color==BLACK) ret++;
        else if(board[y][x]==WHITE && color==WHITE) ret++;
        else break;
    }
    return ret;
}

bool check(int y, int x, int color) {
    if(countLeft(y, x, color)+countRight(y, x, color) == 4) return true;
    else if(countUp(y, x, color)+countDown(y, x, color) == 4) return true;
    else if(countLeftUp(y, x, color)+countRightDown(y, x, color) == 4) return true;
    else if(countRightUp(y, x, color)+countLeftDown(y, x, color) == 4) return true;
    else return false;
}

void print() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        int y, x;
        cin >> y >> x;
        if(i%2) board[y][x] = BLACK;
        else board[y][x] = WHITE;

//        print();

        if(check(y, x, board[y][x])) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}