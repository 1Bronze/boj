/**
 * 16928. 뱀과 사다리 게임
 */

#include <iostream>
#include <queue>
using namespace std;

int N, M;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
bool visited[101];

int bfs() {

    q.push({1, 0});
    visited[1] = true;

    while(!q.empty()) {
        int from = q.front().first;
        int cnt = q.front().second;
        visited[from] = true;
        q.pop();

        if(from>=100)
            return cnt;

        for(int i=1; i<=6; i++) {

            int to = from + i;
            if(visited[to]) continue;

            for(auto& target : v)
                if(target.first == to) to = target.second;

            q.push({to, cnt+1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N+M; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back({from, to});
    }

    cout << bfs();
}