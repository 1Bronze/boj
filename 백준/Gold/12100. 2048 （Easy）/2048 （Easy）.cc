/**
 * 12100. 2048 (Easy)
4
2 4 16 8
8 4 0 0
16 8 2 0
2 8 2 0

for (int a = 1; a <= N; a++) {
    for (int b = 1; b <= N; b++) {
        cout << nextArr[a][b] << " ";
    }
    cout << "\n";
}
cout << "\n";
 */

#define MAX 21

#include <iostream>
using namespace std;

int N, result;
char direction[4] = {'u', 'd', 'l', 'r'};

void dfs(int arr[][MAX], char d, int depth) {

    if(depth==5) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                result = (result>arr[i][j]) ? result:arr[i][j];
            }
        }
        return;
    }

    int nextArr[MAX][MAX];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            nextArr[i][j] = arr[i][j];
        }
    }

    switch (d) {
        case 'u':
            for (int j = 1; j <= N; j++) {
                bool merged[MAX] = {false};
                for (int i = 2; i <= N; i++) {
                    if (nextArr[i][j] == 0) continue;
                    int yPos = i, xPos = j;
                    // i번째 블록의 앞쪽에 공백이 없도록 당겨온다.
                    while (yPos > 1 && nextArr[yPos - 1][xPos] == 0) {
                        nextArr[yPos - 1][xPos] = nextArr[yPos][xPos];
                        nextArr[yPos][xPos] = 0;
                        yPos--;
                    }
                    // i번째 블록과 i-1번째 블록이 합쳐질 수 있고, 앞의 블럭이 합쳐진 적이 없을 경우 합친다.
                    if (yPos > 1 && nextArr[yPos - 1][xPos] == nextArr[yPos][xPos] && !merged[yPos - 1]) {
                        nextArr[yPos - 1][xPos] *= 2;
                        nextArr[yPos][xPos] = 0;
                        merged[yPos - 1] = true;
                    }
                }
            }
            for (int i = 0; i < 4; i++) dfs(nextArr, direction[i], depth+1);
            break;
        case 'd':
            for (int j = 1; j <= N; j++) {
                bool merged[MAX] = { false };
                for (int i = N-1; i >= 1; i--) {
                    if (nextArr[i][j] == 0) continue;
                    int yPos = i, xPos = j;
                    while (yPos < N && nextArr[yPos + 1][xPos] == 0) {
                        nextArr[yPos + 1][xPos] = nextArr[yPos][xPos];
                        nextArr[yPos][xPos] = 0;
                        yPos++;
                    }
                    if (yPos < N && nextArr[yPos + 1][xPos] == nextArr[yPos][xPos] && !merged[yPos + 1]) {
                        nextArr[yPos + 1][xPos] *= 2;
                        nextArr[yPos][xPos] = 0;
                        merged[yPos + 1] = true;
                    }
                }
            }
            for (int i = 0; i < 4; i++) dfs(nextArr, direction[i], depth + 1);
            break;
        case 'l':
            for (int i = 1; i <= N; i++) {
                bool merged[MAX] = { false };
                for (int j = 2; j <= N; j++) {
                    if (nextArr[i][j] == 0) continue;
                    int yPos = i, xPos = j;
                    while (xPos > 1 && nextArr[yPos][xPos - 1] == 0) {
                        nextArr[yPos][xPos - 1] = nextArr[yPos][xPos];
                        nextArr[yPos][xPos] = 0;
                        xPos--;
                    }
                    if (xPos > 1 && nextArr[yPos][xPos - 1] == nextArr[yPos][xPos] && !merged[xPos - 1]) {
                        nextArr[yPos][xPos - 1] *= 2;
                        nextArr[yPos][xPos] = 0;
                        merged[xPos - 1] = true;
                    }
                }
            }
            for (int i = 0; i < 4; i++) dfs(nextArr, direction[i], depth + 1);
            break;
        case 'r':
            for (int i = 1; i <= N; i++) {
                bool merged[MAX] = { false };
                for (int j = N-1; j >= 1; j--) {
                    if (nextArr[i][j] == 0) continue;
                    int yPos = i, xPos = j;
                    while (xPos < N && nextArr[yPos][xPos + 1] == 0) {
                        nextArr[yPos][xPos + 1] = nextArr[yPos][xPos];
                        nextArr[yPos][xPos] = 0;
                        xPos++;
                    }
                    if (xPos < N && nextArr[yPos][xPos + 1] == nextArr[yPos][xPos] && !merged[xPos + 1]) {
                        nextArr[yPos][xPos + 1] *= 2;
                        nextArr[yPos][xPos] = 0;
                        merged[xPos + 1] = true;
                    }
                }
            }
            for (int i = 0; i < 4; i++) dfs(nextArr, direction[i], depth + 1);
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[MAX][MAX];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        dfs(arr, direction[i], 0);
    }

    cout << result;
}
