#include <iostream>
#include <queue>
using namespace std;

int n, m;
int p1, p2;

int tree[101][101];
int answer[101];
queue<int> q;

void bfs() {

    q.push(p1);

    while(!q.empty()) {

        int from = q.front();
        q.pop();

        for(int to = 1; to <= 100; to++) {
            if(tree[from][to]==0) continue;
            if(to==from || answer[to]!=0) continue;

            answer[to] = answer[from] + 1;
            q.push(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> p1 >> p2 >> m;
    for (int i = 1; i <= m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        tree[t1][t2] = 1;
        tree[t2][t1] = 1;
    }

    bfs();

    if(answer[p2]==0) cout << "-1\n";
    else cout << answer[p2];
}