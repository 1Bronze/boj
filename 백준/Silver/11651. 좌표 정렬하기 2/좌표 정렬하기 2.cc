/**
 * 11651. 좌표 정렬하기 2
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct locate {
    int x, y;
};

int N;
vector<locate> v;

bool compare(locate a, locate b) {
    if(a.y != b.y)
        return (a.y < b.y);
    else
        return (a.x < b.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
        cout << v.at(i).x << " " << v.at(i).y << "\n";

    return 0;
}