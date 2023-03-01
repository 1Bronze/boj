/**
 * 10814. 나이순 정렬
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct member {
    int age;
    string name;
};

int N;
vector<member> v;

bool compare(member a, member b) {
    return (a.age < b.age);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int age; string name;
        cin >> age >> name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
        cout << v.at(i).age << " " << v.at(i).name << "\n";

    return 0;
}