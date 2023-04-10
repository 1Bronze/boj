/**
 * 14499. 주사위 굴리기
 */

#include <iostream>
using namespace std;

#define MAX 20
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

struct Dice {
    int xPos, yPos;

    int bottom = 0;
    int top = 0;
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    bool rollUp() {
        if(this->yPos<1) return false;
        int tmp = this->bottom;
        this->bottom = this->up;
        this->up = this->top;
        this->top = this->down;
        this->down = tmp;
        this->yPos--;
        return true;
    }

    bool rollDown(int N) {
        if(this->yPos>=N-1) return false;
        int tmp = this->bottom;
        this->bottom = this->down;
        this->down = this->top;
        this->top = this->up;
        this->up = tmp;
        this->yPos++;
        return true;
    }

    bool rollLeft() {
        if(this->xPos<1) return false;
        int tmp = this->bottom;
        this->bottom = this->left;
        this->left = this->top;
        this->top = this->right;
        this->right = tmp;
        this->xPos--;
        return true;
    }

    bool rollRight(int M) {
        if(this->xPos>=M-1) return false;
        int tmp = this->bottom;
        this->bottom = this->right;
        this->right = this->top;
        this->top = this->left;
        this->left = tmp;
        this->xPos++;
        return true;
    }
};

void setDiceNum(Dice& dice, int map[][MAX]) {
    if(map[dice.yPos][dice.xPos]==0) {
        map[dice.yPos][dice.xPos] = dice.bottom;
    } else {
        dice.bottom = map[dice.yPos][dice.xPos];
        map[dice.yPos][dice.xPos] = 0;
    }
}

void rollDice(Dice& dice, int N, int M, int direction, int map[][MAX]) {
    bool flag;
    switch (direction) {
        case UP:
            flag = dice.rollUp();
            break;
        case DOWN:
            flag = dice.rollDown(N);
            break;
        case LEFT:
            flag = dice.rollLeft();
            break;
        case RIGHT:
            flag = dice.rollRight(M);
            break;
    }

    if(flag) {
        setDiceNum(dice, map);
        cout << dice.top << "\n";
    }
}

void start(Dice& dice, int N, int M, int K, int map[][MAX]) {

    for (int i = 0; i < K; i++) {
        int direction;
        cin >> direction;
        rollDice(dice, N, M, direction, map);
    }
}

void input(int& N, int& M, int& x, int& y, int& K, int map[][MAX]) {
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, y, x, K;
    int map[MAX][MAX];
    input(N, M, y, x, K, map);
    Dice dice;
    dice.xPos = x, dice.yPos = y;
    start(dice, N, M, K, map);
}