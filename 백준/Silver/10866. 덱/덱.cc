/**
 * 10866. 덱
 */

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        string ans;
        int x;

        cin >> ans;
        if(ans=="push_front") {
            cin >> x;
            d.push_front(x);
        } else if(ans=="push_back") {
            cin >> x;
            d.push_back(x);
        } else if(ans=="pop_front") {
            if(d.empty()) cout << "-1\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        } else if(ans=="pop_back") {
            if(d.empty()) cout << "-1\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        } else if(ans=="size") {
            cout << d.size() << "\n";
        } else if(ans=="empty") {
            if(d.empty()) cout << "1\n";
            else cout <<  "0\n";
        } else if(ans=="front") {
            if(d.empty()) cout << "-1\n";
            else cout << d.front() << "\n";
        } else if(ans=="back") {
            if(d.empty()) cout << "-1\n";
            else cout << d.back() << "\n";
        }
    }
}