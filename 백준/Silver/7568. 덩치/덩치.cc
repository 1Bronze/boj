/**
 * 7568. 덩치
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
    int x, y, rank;
};

int N;
vector<person> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y, 1});
    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            if((v.at(i).x < v.at(j).x) && (v.at(i).y < v.at(j).y))
                v.at(i).rank++;
        }
    }

    for (int i = 0; i < N; i++)
        cout << v.at(i).rank << " ";

    return 0;
}