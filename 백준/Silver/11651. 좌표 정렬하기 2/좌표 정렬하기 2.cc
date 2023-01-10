#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
    int a; int b;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(pair<int, int>(b, a));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) cout << v[i].second << " " << v[i].first << "\n";

    return 0;
}