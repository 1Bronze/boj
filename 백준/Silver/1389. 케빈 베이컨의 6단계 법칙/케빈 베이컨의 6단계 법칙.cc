/**
 * 1389. 케빈 베이컨의 6단계 법칙
 */

#define MAX 101

#include <iostream>
#include <queue>
using namespace std;

int N, M;
queue<pair<int, int>> q;
int graph[MAX][MAX];
int kevin[MAX];
pair<int, int> ans = {0, 987654321};

void bfs(int start) {
    while(!q.empty()) {
        int target = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i<=N; i++) {
            if(graph[target][i] && !kevin[i] && start!=i) {
                kevin[i] = cnt+1;
                q.push({i, cnt+1});
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
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int i=1; i<=N; i++) {
        for (int j = 1; j <MAX; j++) kevin[j] = 0;
        q.push({i, 0});
        bfs(i);
        int sum = 0;
        for (int j = 1; j <MAX; j++) sum += kevin[j];

//        cout << i << " " << sum << "\n";
        if(ans.second > sum) {
            ans.first = i;
            ans.second = sum;
        }
    }

    cout << ans.first;
}