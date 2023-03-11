/**
 * 10845.  큐
 */

#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        string ans; cin >> ans;

        if(ans=="push") {
            int n; cin >> n;
            q.push(n);
        }
        else if(ans=="pop") {
            if(!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            } else {
                cout << "-1\n";
            }
        }
        else if(ans=="size") {
            cout << q.size() << "\n";
        }
        else if(ans=="empty") {
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(ans=="front") {
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "-1\n";
        }
        else if(ans=="back") {
            if(!q.empty()) cout << q.back() << "\n";
            else cout << "-1\n";
        }
    }
    
    return 0;
}