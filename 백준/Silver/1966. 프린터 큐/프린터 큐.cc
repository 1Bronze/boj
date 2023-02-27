/**
 * 1966. 프린터 큐
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T, N, M;
queue<pair<int, int>> q;
priority_queue<int> pq;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            q.push(make_pair(i, tmp));
            pq.push(tmp);
        }

        while (!q.empty()) {
            int index = q.front().first;
            int target = q.front().second;

            if(pq.top() > target) {
                q.push(q.front());
                q.pop();
            } else {
                q.pop();
                pq.pop();
                cnt++;

                if(M==index) {
                    cout << cnt << "\n";
                    while(!q.empty()) q.pop();
                    while(!pq.empty()) pq.pop();
                    cnt = 0;
                    break;
                }
            }
        }
    }

    return 0;
}