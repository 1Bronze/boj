/**
 * 18870. 좌표 압축
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int idx;
    int val;
    int comp;
};

int N;
vector<node> v;

bool cmpVal(const node& a, const node& b) {
    return a.val<b.val;
}

bool cmpIdx(const node& a, const node& b) {
    return a.idx<b.idx;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        v.push_back({i, tmp});
    }

    sort(v.begin(), v.end(), cmpVal);

    v[0].comp = 0;
    for (int i = 1; i < v.size(); i++) {
        if(v[i].val==v[i-1].val) v[i].comp = v[i-1].comp;
        else v[i].comp = v[i-1].comp + 1;
    }

    sort(v.begin(), v.end(), cmpIdx);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].comp << " ";

    return 0;
}