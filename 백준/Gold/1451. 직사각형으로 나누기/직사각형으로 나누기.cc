/*
 * 1451. 직사각형으로 나누기
 *
 * 각 칸마다 들어가는 수는 어차피 0 이상 9이하이므로,
 * 한 사각형이 0으로만 구성되는게 아니라면 사각형 안에 포함되지 않는 칸이 없도록 하는게 항상 최대가 된다.
 *
 * 큰 사각형을 작은 사각형 3개로 나누는 방법
 *  (1) 가로 선 두개를 긋는 방법
 *  (2) 세로 선 두개를 긋는 방법
 *  (3) 가로 선, 세로 선을 그어 사각형을 4개로 나눈 후 인접한 사각형 두개를 붙이는 방법
 */

#include <cstdio>
using namespace std;

int N, M;
int square[52][52];
long long s1, s2, s3, result;

long long max(long long a, long long b) {
    return (a>b) ? a:b;
}

// y, x는 직사각형 제일 왼쪽 위의 좌표
// r, c는 직사각형의 세로, 가로의 길이
int sum(int y, int x, int r, int c) {
    int s = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            s += square[y+i][x+j];
        }
    }

    return s;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &square[i][j]);
        }
    }

    // Case1. 가로 선 두개를 그어 사각형을 만드는 경우
    /*
     *  ----------
     * |          |
     * |----------| j
     * |          |
     * |----------| i
     * |          |
     *  ----------
     */
    for (int i = 3; i <= N; i++) {
        for (int j = 2; j < i; j++) {
            s1 = sum(1, 1, j-1, M);
            s2 = sum(j, 1, i-j, M);
            s3 = sum(i, 1, N-i+1, M);
            result = max(result, s1*s2*s3);
        }
    }

    // Case2. 세로 선 두개를 그어 사각형을 만드는 경우
    /*
     *     j   i
     *  -----------
     * |   |   |   |
     * |   |   |   |
     * |   |   |   |
     * |   |   |   |
     *  -----------
     */
    for (int i = 3; i <= M; i++) {
        for (int j = 2; j < i; j++) {
            s1 = sum(1, 1, N, j-1);
            s2 = sum(1, j, N, i-j);
            s3 = sum(1, i, N, M-i+1);
            result = max(result, s1*s2*s3);
        }
    }

    // Case3-1. 가로 선, 세로 선을 그어 사각형을 만드는 경우
    /*
     *       j
     *  -----------
     * |     |     |
     * |     |-----| i
     * |     |     |
     *  -----------
     */
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            s1 = sum(1, 1, N, j-1);
            s2 = sum(1, j, i-1, M-j+1);
            s3 = sum(i, j, N-i+1, M-j+1);
            result = max(result, s1*s2*s3);
        }
    }

    // Case3-2. 가로 선, 세로 선을 그어 사각형을 만드는 경우
    /*
     *       j
     *  -----------
     * |     |     |
     * |-----|     | i
     * |     |     |
     *  -----------
     */
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            s1 = sum(1, 1, i-1, j-1);
            s2 = sum(i, 1, N-i+1, j-1);
            s3 = sum(1, j, N, M-j+1);
            result = max(result, s1*s2*s3);
        }
    }

    // Case3-3. 가로 선, 세로 선을 그어 사각형을 만드는 경우
    /*
     *       j
     *  -----------
     * |           |
     * |-----|-----| i
     * |     |     |
     *  -----------
     */
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            s1 = sum(1, 1, i-1, M);
            s2 = sum(i, 1, N-i+1, j-1);
            s3 = sum(i, j, N-i+1, M-j+1);
            result = max(result, s1*s2*s3);
        }
    }


    // Case3-4. 가로 선, 세로 선을 그어 사각형을 만드는 경우
    /*
     *       j
     *  -----------
     * |     |     |
     * |-----|-----| i
     * |           |
     *  -----------
     */
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            s1 = sum(1, 1, i-1, j-1);
            s2 = sum(1, j, i-1, M-j+1);
            s3 = sum(i, 1, N-i+1, M);
            result = max(result, s1*s2*s3);
        }
    }

    printf("%lld", result);
}