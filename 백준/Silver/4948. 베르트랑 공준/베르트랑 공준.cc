#include <iostream>
using namespace std;

int main() {
    
    int N, cnt = 0;
    int i, j, arr[246913] = {0, };
    
    arr[0] = 1, arr[1] = 1;
    for(j = 2; j < 246913 / j; j++) {
        if(arr[j] == 1) continue;
        for(i = j * j; i < 246913; i += j)
            if(i % j == 0) arr[i] = 1;
    }
    cin >> N;
    
    while(N != 0) {
        cnt = 0;
        for(i = N + 1; i <= N * 2; i++)
            if(arr[i] == 0)
                cnt++;
        cout << cnt << "\n";
        cin >> N;
    }
    return 0;
}
