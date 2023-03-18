/**
 * 5430. AC
 */

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int T;
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--) {
        string p; cin >> p;
        int n; cin >> n;

        char c;
        int tmp = 0;
        while(cin >> c) {
            if(c=='[') continue;

            if(c>=48 && c<58) {
                tmp = tmp*10+(c-'0');
            } else {
                if(n!=0) d.push_back(tmp);
                tmp = 0;
                if(c==']') break;
            }
        }

        bool forward = true;
        bool error = false;
        for (int i = 0; i < p.length(); i++) {
            if(p[i]=='R') {
                forward = !forward;
            } else {
                if(d.empty()) {
                    error = true;
                    break;
                } else {
                    if(forward) d.pop_front();
                    else d.pop_back();
                }
            }
        }

        if(error) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        if(forward && !d.empty()) {
            cout << d.front();
            d.pop_front();
            while(!d.empty()) {
                cout << "," << d.front();
                d.pop_front();
            }
        } else if(!forward && !d.empty()) {
            cout << d.back();
            d.pop_back();
            while(!d.empty()) {
                cout << "," << d.back();
                d.pop_back();
            }
        }
        cout << "]\n";
    }
}