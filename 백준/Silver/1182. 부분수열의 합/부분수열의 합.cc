/**
* 1182. 부분수열의 합
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct data {
    int index;
    int sum;
};

int N, S;
int arr[20];
queue<pair<int, int>> q;
int result;

void bfs(int start) {
    q.push({start, arr[start]});

    while(!q.empty()) {
        int idx = q.front().first;
        int s = q.front().second;
        q.pop();

        if(s==S) result+=1;

        for (int i = idx+1; i < N; i++) {
            q.push({i, s+arr[i]});
        }
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);

    for(int i=0; i<N; i++) bfs(i);
    cout << result;
}