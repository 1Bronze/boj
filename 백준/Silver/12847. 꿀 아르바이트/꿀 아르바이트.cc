#include <iostream>
using namespace std;

int days[100000];
int n, x;
long maxV = 0, curV = 0;

int main() {
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> days[i];

    for(int i=0; i<=n-x; i++) {
        if(i==0) { // 첫 실행 시 days[0]~days[k-1] 까지의 합을 maxV로 설정
            for(int j=0; j<x; j++) curV += days[j];
            maxV = curV;
        } else {
            curV = curV-days[i-1]+days[i+x-1]; // 슬라이딩 윈도우

            if(maxV>curV || curV==0) continue; // 최댓값이 갱신되지 않은 경우
            else // 새로 계산된 값이 더 큰 경우
                maxV = curV;
        }
    }

    cout << maxV;
}