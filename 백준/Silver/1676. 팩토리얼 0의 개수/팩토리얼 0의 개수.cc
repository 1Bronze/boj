#include <iostream>
using namespace std;

int numOfZero[501];
int num[501];

int main() {
    int N; cin >> N;
    
    numOfZero[1] = 0; num[1] = 1;
    
    for(int i=2; i<=N; i++) {
        
        int tmp = num[i-1]*i;
        int cnt = 0;
        while(tmp%10==0) {
            tmp/=10;
            cnt++;
        }
        
        numOfZero[i] = numOfZero[i-1] + cnt;
        num[i] = tmp%1000;
    }

    cout << numOfZero[N];
    return 0;
}
