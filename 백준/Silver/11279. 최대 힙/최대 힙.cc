/**
 * 11279. 최대 힙
 */

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> max_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;

        if(tmp==0) {
            if(max_heap.empty()) cout << "0\n";
            else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        }

        else {
            max_heap.push(tmp);
        }
    }
}