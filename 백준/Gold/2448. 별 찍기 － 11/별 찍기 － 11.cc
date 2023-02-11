/**
* 2448. 별 찍기 - 11
 *
 * === 규칙 ===
 * 입력된 값 N = 높이
 * i번째 행에서 삼각형에 포함되는 칸의 수 = 2i-1
 * 제일 밑변(i=N)의 칸의 수 = 2N-1
 * i번째 행에서 좌우 공백의 수 = N-i
 *
 * index를 (1, 1)부터 시작한다고 하자.
 *
 * 비어있지 않은 곳을 다음 탐색으로 진행시키기 위한 인덱스 변환
 * nextSize = size/2;
 * nextY = (y>N/2) ? y-N/2:y;
 * nextX -> y에 따라 결정
 *  (1) 1<=y<=N/2일 때 -> nextX = x-N/2;
 *  (2) N/2<y<=N일 때 -> nextX = (x>N) ? x-N:x;
*/

#include <iostream>
using namespace std;

int nextX, nextY, nextSize;

void star(int y, int x, int size) {
    if(size==3) {
        if(y==1 && x==3) printf("*");
        else if(y==2 && (x==2 || x==4)) printf("*");
        else if(y==3) printf("*");
        else printf(" ");
        return;
    }

    nextSize = size/2;
    nextY = (y>nextSize) ? y-nextSize:y;

    if(x<=size-y || x>=size+y) printf(" ");
    else {
        if(y==size && x==size) printf(" ");
        else if(1<=y && y<=nextSize) {
            nextX = x-nextSize;
            star(nextY, nextX, nextSize);
        } else {
            nextX = (x>size) ? x-size:x;
            star(nextY, nextX, nextSize);
        }
    }
}

int main() {
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2*N-1; j++) {
            star(i, j, N);
        }
        printf("\n");
    }
}