/**
* 10971. 외판원 순회 2
*/

#include <iostream>
using namespace std;

int arr[11][11];
bool visited[11] = {false, };
int N, result = 2100000000;

int min(int a, int b) {
    return (a<b) ? a:b;
}

void dfs(int pos, int cost, int cnt) {
    if(cnt == N) {
        if(arr[pos][1]!=0) {
            int tmp = cost + arr[pos][1];
            result = min(result, tmp);
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        if(arr[pos][i]==0 && !(i==1 && pos==1)) continue;

        visited[i] = true;
        dfs(i, cost+arr[pos][i], cnt+1);
        visited[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(1, 0, 0);
    cout << result;
}
/*
 * dfs(1,0,0)
 * dfs(1,0,1)
 *    dfs()
 *
 */