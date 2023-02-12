#include <iostream>

using namespace std;

int R, C;
int arr[1002][1002];
int minY = 1000, minX = 1000, minVal = 1000;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void moveL(int &i, int &j) {
    printf("L");
    arr[i][j--] = 0;
}

void moveR(int &i, int &j) {
    printf("R");
    arr[i][j++] = 0;
}

void moveU(int &i, int &j) {
    printf("U");
    arr[i--][j] = 0;
}

void moveD(int &i, int &j) {
    printf("D");
    arr[i++][j] = 0;
}

void move() {
    int targetY, targetX;

    if (minY % 2 == 0) targetY = minY - 1;
    else targetY = minY;

    int i = 1, j = 1;
    while (i != targetY) {
        if(i%2==1 && j!=C) moveR(i, j);
        else if(i%2==0 && j!=1) moveL(i, j);
        else moveD(i, j);
    }

    targetX = minX;
    while(j!=targetX) {
        if(j%2==1) { moveD(i, j); moveR(i, j); }
        else { moveU(i,j); moveR(i, j); }
    }

    while(j!=C) {
        if(j%2==1) { moveR(i, j); moveD(i, j); }
        else { moveR(i, j); moveU(i, j); }
    }

    if(i==R && j==C) return;
    else moveD(i, j);

    while(!(i==R && j==C)) {
        if(i%2==1 && j!=1) moveL(i, j);
        else if(i%2==0 && j!=C) moveR(i, j);
        else moveD(i, j);
    }
}

int main() {
    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];
        }
    }

    if (R % 2 == 1) {
        int i = 1, j = 1;
        while (i != R || j != C) {
            if (arr[i][j + 1] != 0) moveR(i, j);
            else if (arr[i][j - 1] != 0) moveL(i, j);
            else moveD(i, j);
        }
    } else if (C % 2 == 1) {
        int i = 1, j = 1;
        while (i != R || j != C) {
            if (arr[i + 1][j] != 0) moveD(i, j);
            else if (arr[i - 1][j] != 0) moveU(i, j);
            else moveR(i, j);
        }
    } else {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if ((i + j) % 2 == 1 && !(i == 1 && j == 1)) {
                    if (minVal > arr[i][j]) {
                        minVal = min(minVal, arr[i][j]);
                        minY = i;
                        minX = j;
                    }
                }
            }
        }
        arr[minY][minX] = 0;
        move();
    }
}