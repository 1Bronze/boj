/**
* 1992. 쿼드트리
 *
 *
 * 숫자가 다 같다 -> 결과 출력
 * 숫자가 다르다 -> '('출력 & 1, 2, 3, 4분면 분할 & ')' 출력
*/

#include <cstdio>
using namespace std;

int N;
int arr[65][65];
int dy[4] = {0, 0, 1, 1};
int dx[4] = {0, 1, 0, 1};
int nextX, nextY, nextLen;

void compress(int y, int x, int len) {

    bool same = true;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(arr[y][x] != arr[y+i][x+j]) same = false;
        }
    }

    if(same) printf("%d", arr[y][x]);
    else {
        printf("(");
        for (int i = 0; i < 4; i++) {
            nextLen = len/2;
            nextY = y + nextLen * dy[i];
            nextX = x + nextLen * dx[i];
            compress(nextY, nextX, nextLen);
        }
        printf(")");
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    compress(1, 1, N);
}