/**
 * 1967 트리의 지름
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<pair<int, int>> tree[10001];
bool visited[10001] = {false, };
int maxLen = 0, maxNode = 1;

void dfs(int n, int len) {
    if(visited[n]) return;

    visited[n] = true;

    if(maxLen < len) {
        maxLen = len;
        maxNode = n;
    }

    for (int i=0; i<tree[n].size(); i++) {
        int next = tree[n][i].first;
        int l = tree[n][i].second;
        dfs(next, len + l);
    }
}

int main() {
    cin >> N;

    int from, to, distance;
    for (int i = 1; i < N; i++) {
        cin >> from >> to >> distance;
        tree[from].push_back(make_pair(to, distance));
        tree[to].push_back(make_pair(from, distance));
    }

    dfs(1, 0);
    memset(visited, false, 10001);
    maxLen = 0;
    dfs(maxNode, 0);

    cout << maxLen;
}