/**
* 6603. 로또
*/

#include <iostream>
#include <cstring>
using namespace std;

int K;
int arr[13];
bool selected[50];
int cnt;

void dfs(int idx, int n) {
    selected[n] = true;
    cnt++;

    if(cnt==6) {
        for (int i = 0; i < 50; i++)
            if(selected[i]) cout << i << " ";
        cout << "\n";

        selected[n] = false;
        cnt--;
        return;
    }

    for (int i = idx+1; i < K; i++) {
        if(selected[arr[i]]) continue;

        dfs(i, arr[i]);
    }

    selected[n] = false;
    cnt--;
}

int main() {
    while(1) {
        cin >> K;
        if (K == 0) return 0;
        memset(selected, false, 50);
        for (int i = 0; i < K; i++) cin >> arr[i];

        for(int i=0; i<=K-6; i++) dfs(i, arr[i]);
        cout << "\n";
    }
}