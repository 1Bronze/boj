/**
 * 11004. K번째 수
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cout << v.at(K-1);
}