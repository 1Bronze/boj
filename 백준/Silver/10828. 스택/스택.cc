/**
 * 10828. 스택
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;
stack<int> s;
string ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        cin >> ans;

        if(ans=="push") {
            int n; cin >> n;
            s.push(n);
        }
        else if(ans == "top") {
            if (!s.empty()) cout << s.top() << "\n";
            else cout << -1 << "\n";
        }
        else if(ans == "size") {
            cout << s.size() << "\n";
        }
        else if(ans == "empty") {
            if(s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(ans== "pop") {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }
            else cout << -1 << "\n";
        }
    }
}