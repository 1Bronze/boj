/**
* 1167. 트리의 지름
 *
 * 트리의 정보를 입력받은 후, DFS를 이용한다.
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int index; // 연결된 노드의 인덱스
    int dist; // 연결된 노드와의 거리
};

vector<Node> graph[100001];
bool visited[100001];
int maxDist = 0;
int maxNode;

void dfs(int n, int d) {

    if(visited[n]) return;

    if(maxDist < d) {
        maxNode = n;
        maxDist = d;
    }

    visited[n] = true;
    for (int i = 0; i < graph[n].size(); i++) {
        int nextNode = graph[n][i].index;
        int nextDist = graph[n][i].dist;

        dfs(nextNode, d+nextDist);
    }

}

int main() {
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        int n; cin >> n;

        while(1) {
            int a; cin >> a;
            if (a == -1) break;
            int b; cin >> b;

            Node node;
            node.index = a;
            node.dist = b;

            graph[n].push_back(node);
        }
    }

    dfs(1, 0);
    memset(visited, false, 100001);
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist;
}
