/**
 * 11062. 카드 게임
 *
 * n=짝수일 때
 * (1) 1장 남은 경우 (i==j)
 *     남은 1장을 가져가는 것은 명우이므로 DP[i][j] = 0
 * (2) 2장 이상 남은 경우 중 j-i가 짝수일 때 (남은 카드의 개수가 짝수, 즉 근우의 차례일 때)
 *     근우가 왼쪽 카드를 가져가거나 오른쪽 카드를 가져가거나
 *         근우가 왼쪽 카드를 가져감 -> DP[i][j] = DP[i+1][j] + cards[i]
 *         근우가 오른쪽 카드를 가져감 -> DP[i][j] = DP[i][j-1] + cards[j]
 *         => 근우는 항상 큰 결과가 나오도록 선택하므로 위의 두 개의 값 중 더 큰게 실제 DP[i][j]가 됨.
 * (3) 2장 이상 남은 경우 중 j-i가 홀수일 때 (남은 카드의 개수가 홀수, 즉 명우의 차례일 때)
 *         명우가 왼쪽 카드를 가져감 -> DP[i][j] = DP[i+1][j]
 *         명우가 오른쪽 카드를 가져감 -> DP[i][j] = DP[i][j-1]
 *         => 명우는 항상 근우에게 안좋은 결과가 나오도록 선택하므로 위의 두 개의 값 중 더 작은게 실제 DP[i][j]가 됨.
 *
 * n=홀수일 때
 * (1) 1장 남은 경우 (i==j)
 *     남은 1장을 가져가는 것은 근우이므로 DP[i][j] = cards[i]
 * (2) 2장 이상 남은 경우 중 j-i가 홀수일 때 (남은 카드의 개수가 홀수, 즉 근우의 차례일 때)
 *     근우가 왼쪽 카드를 가져가거나 오른쪽 카드를 가져가거나
 *         근우가 왼쪽 카드를 가져감 -> DP[i][j] = DP[i+1][j] + cards[i]
 *         근우가 오른쪽 카드를 가져감 -> DP[i][j] = DP[i][j-1] + cards[j]
 *         => 근우는 항상 큰 결과가 나오도록 선택하므로 위의 두 개의 값 중 더 큰게 실제 DP[i][j]가 됨.
 * (3) 2장 이상 남은 경우 중 j-i가 짝수일 때 (남은 카드의 개수가 짝수, 즉 명우의 차례일 때)
 *         명우가 왼쪽 카드를 가져감 -> DP[i][j] = DP[i+1][j]
 *         명우가 오른쪽 카드를 가져감 -> DP[i][j] = DP[i][j-1]
 *         => 명우는 항상 근우에게 안좋은 결과가 나오도록 선택하므로 위의 두 개의 값 중 더 작은게 실제 DP[i][j]가 됨.
 */

#include <iostream>
using namespace std;

#define MAX 1002

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    for (int i = 0; i < T; i++) solve();
}

void solve() {

    // cards[i] : 입력으로 주어진 카드의 배열
    int cards[MAX] = {0, };
    // DP[i][j] : i~j까지 카드가 남았을 때, 근우가 얻을 수 있는 점수의 최댓값
    int DP[MAX][MAX] = {0, };

    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> cards[i];

    // firstTurn: 마지막이 근우의 차례면 true, 명우의 차례면 false
    bool firstTurn = true;
    if(N % 2 == 0) firstTurn = false;

    for (int i = 1; i <= N; i++) {
        // 대각선으로 내려가는 로직
        for (int j = 1; j <= N - i + 1; j++) {

            int r = j;
            int c = i + j - 1;

            // 근우 차례는 항상 최대값을 갖도록
            if (firstTurn) DP[r][c] = max(DP[r + 1][c] + cards[r], DP[r][c - 1] + cards[c]);
            // 명우 차례는 항상 최소값을 갖도록
            else DP[r][c] = min(DP[r + 1][c], DP[r][c - 1]);
        }

        firstTurn = !firstTurn;
    }

    cout << DP[1][N] << "\n";
}