/**
* 1783. 병든 나이트
*/

#include <iostream>
using namespace std;

int dy[4] = {2, 1, -1, -2};
int dx[4] = {1, 2, 2, 1};

int N, M, result;

int main() {
    cin >> N >> M;

    // 우선 4번 이상 가야하는 경우와 3번 이하로 가는 경우를 나눈다.

    // 4번 이상 가는 경우
    if(N>=3 && M>=7) {
        result = M-2;
    }
    // 3번 이하로 가는 경우
    else {
        // 이동할 수 없는 경우
        if(N==1 || M==1) result = 1;
        else if(N==2 && M==2) result = 1;
        // 한번 이동할 수 있는 경우
        else if(N>=3 && M==2) result = 2;
        else if(N==2 && (M==3 || M==4)) result = 2;
        // 두번 이동할 수 있는 경우
        else if(N>=3 && M==3) result = 3;
        else if(N==2 && (M==5 || M==6)) result = 3;
        // 세번 이동할 수 있는 경우
        else result = 4;
    }

    cout << result;
}