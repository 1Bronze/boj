/**
 * 18111. 마인크래프트
 */

#define MAX 500

#include <iostream>

using namespace std;

int N, M, B;
int world[MAX][MAX];
int height, result = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> world[i][j];
        }
    }

    for (int h = 0; h <= 256; h++) {
        int time = 0, blocks = B;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (world[i][j] > h) {
                    time += 2 * (world[i][j] - h);
                    blocks += (world[i][j] - h);
                } else {
                    time += (h - world[i][j]);
                    blocks -= (h - world[i][j]);
                }
            }
        }

        if (blocks >= 0 && time <= result)
            height = h, result = time;
    }

    cout << result << " " << height << "\n";
    return 0;
}