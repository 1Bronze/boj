/**
 * 14891. 톱니바퀴
 */

#include <iostream>
using namespace std;

struct Gear {
    int arr[8];
    int top = 0, lPos = 6, rPos = 2;
};

Gear gears[4];
int dx[2] = {-1, 1};
int K, result;
bool visited[4];

void turnRight(int idx);
void turnLeft(int idx);

void turnRight(int idx) {

    visited[idx] = true;

    for (int i = 0; i < 2; i++) {
        int nextIdx = idx + dx[i];
        if(nextIdx<0 || nextIdx>3 || visited[nextIdx]) continue;

        // 왼쪽 기어에 영향을 미침.
        if(i==0 && gears[idx].arr[gears[idx].lPos]!=gears[nextIdx].arr[gears[nextIdx].rPos]) turnLeft(nextIdx);
        // 오른쪽 기어에 영향을 미침.
        else if(i==1 && gears[idx].arr[gears[idx].rPos]!=gears[nextIdx].arr[gears[nextIdx].lPos]) turnLeft(nextIdx);
    }

    gears[idx].top -= 1;
    gears[idx].lPos -= 1;
    gears[idx].rPos -= 1;
    if(gears[idx].top < 0) gears[idx].top += 8;
    if(gears[idx].lPos < 0) gears[idx].lPos += 8;
    if(gears[idx].rPos < 0) gears[idx].rPos += 8;

    visited[idx] = false;
}

void turnLeft(int idx) {

    visited[idx] = true;

    for (int i = 0; i < 2; i++) {
        int nextIdx = idx + dx[i];
        if(nextIdx<0 || nextIdx>3 || visited[nextIdx]) continue;

        // 왼쪽 기어에 영향을 미침.
        if(i==0 && gears[idx].arr[gears[idx].lPos]!=gears[nextIdx].arr[gears[nextIdx].rPos]) turnRight(nextIdx);
        // 오른쪽 기어에 영향을 미침.
        else if(i==1 && gears[idx].arr[gears[idx].rPos]!=gears[nextIdx].arr[gears[nextIdx].lPos]) turnRight(nextIdx);
    }

    gears[idx].top += 1;
    gears[idx].lPos += 1;
    gears[idx].rPos += 1;
    if(gears[idx].top > 7) gears[idx].top -= 8;
    if(gears[idx].lPos > 7) gears[idx].lPos -= 8;
    if(gears[idx].rPos > 7) gears[idx].rPos -= 8;

    visited[idx] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <8 ; j++) {
            cin >> c;
            gears[i].arr[j] = c - '0';
        }
    }

    cin >> K;
    while(K--) {
        int idx, cnt;
        bool isRight;
        cin >> idx >> cnt;
        isRight = (cnt>0);
        cnt = (isRight) ? cnt:-cnt;

        for (int i = 1; i <= cnt; i++) {
            if(isRight) turnRight(idx-1);
            else turnLeft(idx-1);
        }
    }

    if(gears[0].arr[gears[0].top] == 1) result += 1;
    if(gears[1].arr[gears[1].top] == 1) result += 2;
    if(gears[2].arr[gears[2].top] == 1) result += 4;
    if(gears[3].arr[gears[3].top] == 1) result += 8;

    cout << result << "\n";
}