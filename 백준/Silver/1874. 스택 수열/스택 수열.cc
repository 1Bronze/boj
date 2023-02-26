/**
 * 1874. 스택 수열
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
stack<int> s;
vector<char> v;
int cnt = 1;

void pushAndPrint(int a) {
    s.push(a);
    v.push_back('+');
}

void popAndPrint() {
    s.pop();
    v.push_back('-');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int target; cin >> target;

        while(cnt <= target) pushAndPrint(cnt++);

        if(s.top()==target) popAndPrint();
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int j = 0; j < v.size(); j++)
        cout << v.at(j) << "\n";
}