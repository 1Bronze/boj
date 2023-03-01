/**
 * 2108. 통계학
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int N;
map<int, int> m;
double avg, mid, mode, range;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        avg += tmp;

        if(m.find(tmp)==m.end())
            m.insert({tmp, 1});
        else
            m.at(tmp)++;
    }

    int maximum = -987654321;
    int minimum = 987654321;
    pair<int, int> tmp = {0, 0};
    int before_cnt = 0, after_cnt = 0; bool isSecond = false;
    for (const auto i: m) {
        after_cnt += i.second;
        maximum = max(maximum, i.first);
        minimum = min(minimum, i.first);
        if(before_cnt < (N+1)/2 && after_cnt >= (N+1)/2) mid = i.first;
        if(tmp.second<i.second) {
            isSecond = false;
            tmp.first = i.first;
            tmp.second = i.second;
        } else if(tmp.second==i.second && !isSecond) {
            isSecond = true;
            tmp.first = i.first;
            tmp.second = i.second;
        }
        before_cnt = after_cnt;
    }

    range = maximum - minimum;
    avg /= N;
    avg = round(avg);
    mode = tmp.first;

    if(avg == -0) avg = 0;

    cout << avg << "\n";
    cout << mid << "\n";
    cout << mode << "\n";
    cout << range << "\n";
}