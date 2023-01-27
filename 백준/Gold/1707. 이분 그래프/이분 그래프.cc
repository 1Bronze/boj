#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[20001];
bool visited[20001];
char group[20001];
int K, N, M;
bool result;

void dfs(int x) {
    visited[x] = true;

    // 주위 노드의 그룹 설정
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (group[y] == 'n') {
            if (group[x] == 'a') group[y] = 'b';
            if (group[x] == 'b') group[y] = 'a';
        }
    }

    // 주위 노드와 그룹이 다른지 확인
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];

        if (group[x] == group[y])
            result = false;
    }

    // 주위 노드 방문
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];

        if (!visited[y]) dfs(y);
    }
}

int main() {

    cin >> K;

    for(int i=1; i<=K; i++) {
        cin >> N >> M;

        // 노드, 간선 정보 입력
        int x, y;
        for(int j=1; j<=M; j++) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // 초기화
        result = true;
        for (int j=1; j<=N; j++) {
            visited[j] = false;
            group[j] = 'n';
            sort(graph[j].begin(), graph[j].end());
        }
        group[1] = 'a';

        dfs(1);
        for(int j=2; j<=N; j++) {
            if(!visited[j] && result) {
                group[j] = 'a';
                dfs(j);
            }
            else if(!visited[j] && !result) {
                result = false;
                break;
            }
        }

        if(result) cout << "YES\n";
        else cout << "NO\n";

        for(int j=1; j<=N; j++) graph[j].clear();
    }

    return 0;
}