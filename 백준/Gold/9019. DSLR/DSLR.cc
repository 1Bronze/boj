#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

int T, from, to;
bool visited[10000];

void bfs() {
    queue<pair<int, string>> q;
    q.push(make_pair(from, ""));
    visited[from] = true;

    while (!q.empty()) {
        int target = q.front().first;
        string path = q.front().second;
        q.pop();

        if (target == to) {
            cout << path << "\n";
            return;
        }

        int d = (target * 2) % 10000;
        if(!visited[d]) {
            visited[d] = true;
            q.push(make_pair(d, path + 'D'));
        }

        int s = target - 1 < 0 ? 9999 : target - 1;
        if(!visited[s]) {
            visited[s] = true;
            q.push(make_pair(s, path + 'S'));
        }

        int l = (target % 1000) * 10 + (target / 1000);
        if(!visited[l]) {
            visited[l] = true;
            q.push(make_pair(l, path + 'L'));
        }

        int r = target / 10 + (target % 10) * 1000;
        if(!visited[r]) {
            visited[r] = true;
            q.push(make_pair(r, path + 'R'));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> from >> to;
        memset(visited, false, sizeof(visited));
        bfs();
    }
}