/**
 * 10773. 제로
 */

#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;

        if(tmp==0) s.pop();
        else s.push(tmp);
    }

    while(!s.empty()) {
        int target = s.top();
        s.pop();
        sum += target;
    }

    cout << sum << "\n";
    return 0;
}