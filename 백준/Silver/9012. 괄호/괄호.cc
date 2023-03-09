/**
 * 9012. 괄호
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T;
stack<char> s;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> str;

        while(!s.empty()) s.pop();

        for (int i = 0; i < str.size(); i++) {
           if(s.empty()) s.push(str[i]);
            else {
               if (s.top() == '(' && str[i] == ')') s.pop();
               else s.push(str[i]);
           }
        }

        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}