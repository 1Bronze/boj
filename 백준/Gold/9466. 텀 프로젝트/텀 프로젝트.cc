#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int t, n;
int graph[MAX];
bool visited[MAX];
bool done[MAX];
int cnt;

void hasCycle(int node) { // node부터 사이클 탐색 시작

    visited[node] = true;
    int next = graph[node];

    if(!visited[next]) { // 다음 노드를 방문한 적이 없으면 방문한다.
        hasCycle(next);
    } else if(!done[next]) { // 방문한 적이 있고 사이클이 만들어지지 않은 노드라면

        // 사이클의 시작부분(사이클의 마지막 노드가 가리키는 노드)부터 사이클에 연결된 노드의 개수를 센다.
        for(int i = next; i != node; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }

    // 사이클에 속한 노드는 당연히 다시 방문할 일 없고,
    // 사이클 내에 들어있지 않더라도 사이클과 연결되어 있다면 결국 다른 사이클을 이루지 못함. (무조건 기존 사이클로 들어가므로)
    done[node] = true;
}

int main() {
    cin >> t;

    while(t--) {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        cin >> n;

        for(int i=1; i<=n; i++) cin >> graph[i];

        cnt = 0;
        for(int i=1; i<=n; i++)
            if(!visited[i]) hasCycle(i);

        cout << n - cnt << "\n";
    }

    return 0;
}