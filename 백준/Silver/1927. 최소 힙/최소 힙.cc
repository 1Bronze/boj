/**
 * 1927. 최소 힙
 */

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        int x; cin >> x;

        if(x==0) {
            if(!q.empty()) {
                cout << q.top() << "\n";
                q.pop();
            } else {
                cout << "0\n";
            }
        }
        else {
            q.push(x);
        }
    }
}