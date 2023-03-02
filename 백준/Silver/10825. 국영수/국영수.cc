/**
 * 10825. 국영수
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int korean, english, math;
};

int N;
vector<Student> v;

bool compare(Student a, Student b) {
    if(a.korean!=b.korean)
        return (a.korean > b.korean);
    else if(a.english != b.english)
        return (a.english < b.english);
    else if(a.math != b.math)
        return (a.math > b.math);
    else
        return (a.name < b.name);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        v.push_back({name, korean, english, math});
    }

    sort(v.begin(), v.end(), compare);

    for (const auto s: v)
        cout << s.name << "\n";

    return 0;
}