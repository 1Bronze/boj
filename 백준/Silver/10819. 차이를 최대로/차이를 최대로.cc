/**
* 10819. 차이를 최대로
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector<int> v;
int arr[8];
bool selected[8] = {false, };
int result;

int max(int a, int b) {
    return a>b ? a:b;
}

void calculate() {
    int tmp = 0;
    for (int i = 0; i < v.size()-1; i++) {
        tmp += abs(v.at(i)-v.at(i+1));
    }

    result = max(result, tmp);
}

void dfs(int cnt) {
    if(cnt==N) {
        calculate();
        return;
    }

    for (int i = 0; i < N; i++) {
        if(selected[i]) continue;

        selected[i] = true;
        v.push_back(arr[i]);
        dfs(cnt+1);
        v.pop_back();
        selected[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >>  arr[i];

    dfs(0);
    cout << result;
}