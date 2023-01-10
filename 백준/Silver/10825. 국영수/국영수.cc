#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int kor, eng, math;
};

int N;
vector<Student> v;

bool compare(const Student &a, const Student &b) {

    if(a.kor != b.kor) // 국어 점수 비교
        return a.kor > b.kor;
    if(a.eng != b.eng) // 국어 점수가 같으면 영어 점수 비교
        return a.eng < b.eng;
    if(a.math != b.math) // 국어, 영어 점수가 같으면 수학 점수 비교
        return a.math > b.math;
    else // 국어, 영어, 수학 점수가 모두 같으면 사전순 배열
        return a.name < b.name;
}

int main() {
    Student s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }

    stable_sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) cout << v[i].name << "\n";

    return 0;
}