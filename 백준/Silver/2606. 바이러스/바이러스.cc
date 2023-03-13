/**
 * 2606. 바이러스
 */

#define MAX 101

#include <iostream>
#include <queue>
using namespace std;

bool net[MAX][MAX];
bool visited[MAX];
queue<int> q;
int N, M, cnt;

void bfs() {
    visited[1] = true;
    q.push(1);

    while(!q.empty()) {
        int from = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if(net[from][i] && !visited[i]) {
                visited[i] = true;
                cnt++;
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        net[a][b] = true;
        net[b][a] = true;
    }

    bfs();
    cout << cnt;
}