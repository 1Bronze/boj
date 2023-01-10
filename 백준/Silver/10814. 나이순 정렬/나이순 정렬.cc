#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
vector<pair<int, string>> v;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int age; string name;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        v.push_back(pair<int, string>(age, name));
    }

    stable_sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}