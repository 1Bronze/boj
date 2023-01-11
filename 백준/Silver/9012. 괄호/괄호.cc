#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int T; string str;
stack<char> s;

int main() {
    scanf("%d", &T);

    char target;
    for (int i = 0; i < T; i++) {
        cin >> str;

        // target: 제일 위에서 두번째에 위치한 원소
        s.push(str[0]); target = str[0];
        for(int j = 1; j < str.length(); j++) {
            s.push(str[j]);

            if(target=='(' && s.top()==')') {
                s.pop();
                s.pop();
            }

            if(s.empty()) s.push(str[++j]);
            target = s.top();
        }

        string result = (s.top()=='\0') ? "YES":"NO";
        cout << result << "\n";

        while( !s.empty() ) s.pop();
    }

    return 0;
}