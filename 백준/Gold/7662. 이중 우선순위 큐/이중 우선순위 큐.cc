#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        bool valid[1000001];

        cin >> k;
        for (int i = 1; i <= k; i++) {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                min_heap.push(make_pair(n, i));
                max_heap.push(make_pair(n, i));
                valid[i] = true;
            } if(c == 'D') {
                // -1이 입력으로 들어온 경우 -> 최솟값을 빼야 한다.
                if (n == -1) {
                    if(min_heap.empty()) continue;

                    // min_heap에서는 pop만 해주면 된다.
                    // max_heap에 의해 이미 빠진 값이 존재한다면 제거해준다.
                    while(!min_heap.empty()) {
                        if(!valid[min_heap.top().second]) min_heap.pop();
                        else break;
                    }

                    if(!min_heap.empty()) {
                        int idx = min_heap.top().second;
                        // 이제 최솟값을 빼준다.
                        min_heap.pop();
                        // max_heap에서의 동기화를 위해 valid의 값은 false로 설정한다.
                        valid[idx] = false;
                    }
                }

                // 1이 입력으로 들어온 경우 -> 최댓값을 빼야 한다.
                else{
                    if(max_heap.empty()) continue;

                    // max_heap에서는 pop만 해주면 된다.
                    // min_heap에 의해 이미 빠진 값이 존재한다면 제거해준다.
                    while(!max_heap.empty()) {
                        if(!valid[max_heap.top().second]) max_heap.pop();
                        else break;
                    }

                    // min_heap에서의 동기화를 위해 valid의 값은 false로 바꿔두자.
                    if(!max_heap.empty()) {
                        int idx = max_heap.top().second;
                        // 이제 최댓값을 빼준다.
                        max_heap.pop();
                        // min_heap에서의 동기화를 위해 valid의 값은 false로 설정한다.
                        valid[idx] = false;
                    }
                }
            }
        }

        // 동기화
        while(!min_heap.empty()) {
            int idx = min_heap.top().second;
            if(valid[idx]) break;
            min_heap.pop();
        }
        while(!max_heap.empty()) {
            int idx = max_heap.top().second;
            if(valid[idx]) break;
            max_heap.pop();
        }

        if(min_heap.empty() && max_heap.empty()) cout << "EMPTY\n";
        else cout << max_heap.top().first << " " << min_heap.top().first << "\n";
    }
}