/**
 * 4949. 균형잡힌 세상
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        while (!s.empty()) s.pop();

        bool check = false;
        getline(cin, str);
        if (str == ".") break;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] != '(' && str[i] != ')' && str[i] != '[' && str[i] != ']') continue;

            if (str[i] == '(' || str[i] == '[') s.push(str[i]);
            else {
                if (s.empty()) {
                    cout << "no\n";
                    check = true;
                    break;
                }

                if (str[i] == ']' && s.top() == '[') s.pop();
                else if (str[i] == ')' && s.top() == '(') s.pop();
                else {
                    cout << "no\n";
                    check = true;
                    break;
                }
            }
        }

        if(!check) {
            if (s.empty()) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}