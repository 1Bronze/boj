/**
 * 14503. 로봇 청소기
 */

#include <iostream>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Robot {
    int y, x, d;
};

int N, M, result;
Robot robot;
int arr[50][50];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool check() {
    for (int i = 0; i < 4; i++) {

        int ny = robot.y+dy[i];
        int nx = robot.x+dx[i];

        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(arr[ny][nx]==0) return true;
    }

    return false;
}

void turnLeft() {
    robot.d--;
    if(robot.d<0) robot.d+=4;
}

bool movableFront() {
    int ny = robot.y+dy[robot.d];
    int nx = robot.x+dx[robot.d];

    if(ny<0 || ny>=N || nx<0 || nx>=M) return false;
    else return (arr[ny][nx]==0);
}

bool movableBack() {
    int ny = robot.y+dy[(robot.d+2)%4];
    int nx = robot.x+dx[(robot.d+2)%4];

    if(ny<0 || ny>=N || nx<0 || nx>=M) return false;
    else return !(arr[ny][nx]==1);
}

void moveFront() {
    robot.y = robot.y+dy[robot.d];
    robot.x = robot.x+dx[robot.d];
}

void moveBack() {
    robot.y = robot.y+dy[(robot.d+2)%4];
    robot.x = robot.x+dx[(robot.d+2)%4];
}

void clean() {
    arr[robot.y][robot.x] = 2;

    // 주위 4칸 중 비어있는 곳이 존재하면
    if(check()) {
        for (int i = 0; i < 4; i++) {
            turnLeft();
            if(movableFront()) {
                moveFront();
                clean();
                return;
            }
        }
    }
    // 주위 4칸 중 비어있는 곳이 존재하지 않으면
    else {
        if(movableBack()) {
            moveBack();
            clean();
            return;
        }
    }
}

void count() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(arr[i][j] == 2) result++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> robot.y >> robot.x >> robot.d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    clean();
    count();
    cout << result << "\n";
}