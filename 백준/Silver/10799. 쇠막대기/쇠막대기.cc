/**
 * 10799. 쇠막대기
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
vector<char> v;
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; cin >> str;
    str.push_back('(');

    for (int i = 0; i < str.length(); i++) {

        if(str[i]=='(' && str[i+1]==')') {
            result += s.size();
            i++;
        } else if(str[i] == '(') {
            s.push(str[i]);
        } else {
            result++;
            s.pop();
        }
    }

    cout << result << "\n";
    return 0;

}