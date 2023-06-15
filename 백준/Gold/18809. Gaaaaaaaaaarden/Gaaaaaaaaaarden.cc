/**
 * 18809. Gaaaaaaaaaarden
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

#define GREEN 1
#define RED 2
#define FLOWER 3

#define LAKE 0
#define LAND 1
#define SOW_LAND 2

#define Y first
#define X second

#define TYPE first
#define DIST second
#define POS second

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, G, R;
int graph[MAX][MAX];
int ans;

vector<pair<int, int>> sowLandList;

void input();

void solve();

void bfs(vector<pair<int, int>> &greenLand, vector<pair<int, int>> &redLand);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    cout << ans << "\n";
}

void input() {

    cin >> N >> M >> G >> R;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 정원의 타입(호수 or Land or Sowland)을 입력받음.
            cin >> graph[i][j];

            // SowLand만 별도로 벡터에 저장
            if (graph[i][j] == SOW_LAND)
                sowLandList.push_back({i, j});
        }
    }
}

void solve() {
    /* greenPos[i]=1이면
     * sowLandList[i]의 좌표에 초록색 배양액을 놓은 것이다.
     */
    vector<int> greenPos;
    vector<int> redPos;

    // r과 n-r의 개수만큼 0,1을 채워넣는다.
    for (int i = 0; i < sowLandList.size(); i++) {
        if (i < sowLandList.size() - G) greenPos.push_back(0);
        if (i >= sowLandList.size() - G) greenPos.push_back(1);
    }
    // r과 n-r의 개수만큼 0,1을 채워넣는다.
    for (int i = 0; i < sowLandList.size() - G; i++) {
        if (i < sowLandList.size() - (G + R)) redPos.push_back(0);
        if (i >= sowLandList.size() - (G + R)) redPos.push_back(1);
    }

    do {

        // greenPos[i] = 1인 i를 찾으면 그때 sowLandList[i]에
        // 저장된 값이 실제 초록색 배양액이 위치할 좌표일 것이다.
        // 실제 초록색 배양액이 뿌려질 곳들의 좌표를 greenLand 벡터에 저장한다.
        vector<pair<int, int>> greenLand;

        for (int i = 0; i < sowLandList.size(); i++)
            if (greenPos[i] == 1)
                greenLand.push_back(sowLandList[i]);

        do {

            // redPos[i] = 1인 i를 찾으면 그때 sowLandList[i]에
            // 저장된 값이 실제 빨간색 배양액이 위치할 좌표일 것이다.
            // 실제 빨간색 배양액이 뿌려질 곳들의 좌표를 redLand 벡터에 저장한다.
            vector<pair<int, int>> redLand;

            for (int i = 0; i < redPos.size(); i++) {
                if (redPos[i] != 1) continue;

                // redPos[i]와 greenPos[i]가 모두 1일 수는 없다.
                // 초록색 배양액을 놓지 않은 위치에만 빨간색 배양액을 놓는다.
                int flag = 0;
                for (int j = 0; j < greenPos.size(); j++) {
                    if (greenPos[j] == 0) {
                        flag++;
                        if (flag == i + 1)
                            redLand.push_back(sowLandList[j]);
                    }
                }
            }
            // 초록색, 빨간색 배양액을 놓은 뒤 bfs를 진행한다.
            bfs(greenLand, redLand);
        } while (next_permutation(redPos.begin(), redPos.end()));
    } while (next_permutation(greenPos.begin(), greenPos.end()));
}

void bfs(vector<pair<int, int>> &greenLand, vector<pair<int, int>> &redLand) {

    // visited:（배양액의 종류, 도달하는데 걸린 시간）
    pair<int, int> visited[MAX][MAX];

    // BFS를 수행하기 위한 queue (배양액의 종류, (y좌표, x좌표))
    queue<pair<int, pair<int, int>>> q;

    // 초록색 배양액을 queue에 넣고 방문 표시
    for (auto position: greenLand) {
        q.push({GREEN, position});
        visited[position.Y][position.X].TYPE = GREEN;
        visited[position.Y][position.X].DIST = 1;
    };

    // 빨간색 배양액을 queue에 넣고 방문 표시
    for (auto position: redLand) {
        q.push({RED, position});
        visited[position.Y][position.X].TYPE = RED;
        visited[position.Y][position.X].DIST = 1;
    };

    // 피울 수 있는 꽃의 개수
    int cnt = 0;

    while (!q.empty()) {

        pair<int, pair<int, int>> cur = q.front();
        q.pop();

        // 꽃을 피운 위치는 배양액을 퍼트리지 않음
        if (visited[cur.POS.Y][cur.POS.X].TYPE == FLOWER) continue;

        for (int i = 0; i < 4; i++) {
            int ny = cur.POS.Y + dy[i];
            int nx = cur.POS.X + dx[i];

            // 정원의 인덱스를 벗어나는 경우 탐색x
            if (ny < 1 || nx < 1 || ny > N || nx > M) continue;
            // 인접한 좌표가 호수인 경우
            if (graph[ny][nx] == LAKE) continue;

            // 방문하지 않은 경우
            if (visited[ny][nx].DIST == 0) {

                q.push({cur.TYPE, {ny, nx}});

                // 동일한 시간에 도달했는 지 확인하기 위해 방문 표시 배열에 dist도 저장
                visited[ny][nx].DIST = visited[cur.POS.Y][cur.POS.X].DIST + 1;
                // 어떤 배양액으로 부터 퍼진 것인지 표시
                visited[ny][nx].TYPE = cur.TYPE;
            }
                // 초록색 배양액과 빨간색 배양액이 동일한 시간에 도달한 경우
            else if ((visited[ny][nx].DIST == visited[cur.POS.Y][cur.POS.X].DIST + 1) &&
                     (visited[ny][nx].TYPE == GREEN && cur.TYPE == RED ||
                      visited[ny][nx].TYPE == RED && cur.TYPE == GREEN)) {

                visited[ny][nx].TYPE = FLOWER;
                cnt++;
            }
        }
    }

    ans = max(ans, cnt);
}