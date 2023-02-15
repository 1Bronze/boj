/**
* 5014. 스타트링크
 *
 * F >> S >> G >> U >> D
 * F층짜리 건물에서 현재 S층, G층이 목표.
 * U층만큼 올라가거나 D층만큼 내려가기만 가능.
*/

#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
queue<pair<int, int>> q;
int result = 10000000;

//int min(int a, int b) {
//    return (a<b) ? a:b;
//}
//
//void dfs(int now, int cnt) {
//    if(visited[now]) return;
//    if(now<1 || now>1000000) return;
//
//    visited[now] = true;
//    if(now==G) {
//        result = min(result, cnt);
//        visited[now] = false;
//        return;
//    }
//
//    if(now+U<=F && U!=0) dfs(now+U, cnt+1);
//    if(now-D>=1 && D!=0) dfs(now-D, cnt+1);
//    visited[now] = false;
//}

void bfs() {
    visited[S] = true;
    q.push(make_pair(S, 0));

    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now==G) {
            cout << cnt;
            return;
        }

        if(now+U<=F && U!=0 && !visited[now+U]) {
            visited[now+U] = true;
            q.push(make_pair(now+U, cnt+1));
        }

        if(now-D>=1 && D!=0 && !visited[now-D]) {
            visited[now-D] = true;
            q.push(make_pair(now-D, cnt+1));
        }
    }

    cout << "use the stairs";
    return;
}

int main() {
    cin >> F >> S >> G >> U >> D;
//    dfs(S, 0);
    bfs();
    return 0;
}

/*

80 45 32 5 19
answer 7

1000000 1000000 1 0 1
answer 999999

 */