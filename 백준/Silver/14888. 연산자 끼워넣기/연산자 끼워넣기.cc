/**
 * 14888. 연산자 끼워넣기
 */

#include <iostream>
#include <cmath>
using namespace std;

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4

int N;
int n[12];
int operators[5];
int maxi = -2147483648, mini = 2147483647;

void calculate(int idx, int sum) {

    if(idx==N) {
        maxi = max(maxi, sum);
        mini = min(mini, sum);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        if(operators[i]==0) continue;

        operators[i]--;
        int tmp;
        if(i==ADD) tmp = sum+n[idx+1];
        else if(i==SUB) tmp = sum-n[idx+1];
        else if(i==MUL) tmp = sum*n[idx+1];
        else tmp = sum/n[idx+1];
        calculate(idx+1, tmp);
        operators[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> n[i];
    for (int i = 1; i <= 4; i++) cin >> operators[i];

    calculate(1, n[1]);
    cout << maxi << "\n" << mini << "\n";
}