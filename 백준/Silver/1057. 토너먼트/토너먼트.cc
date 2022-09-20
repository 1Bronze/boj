#include <iostream>
using namespace std;

int main() {
    int partcp = 0, jimin = 0, hansu = 0;
    int cnt = 1;

    cin >> partcp >> jimin >> hansu;

    while(true) {

        if(min(jimin, hansu)%2==1 && abs(jimin-hansu)==1) {// 같은 시합에서 만날 경우
            cout << cnt << endl; // 경기 횟수 출력
            break;
        }

        if(jimin%2 == 0)
            jimin /= 2;
        else
            jimin = (jimin+1)/2;

        if(hansu%2 == 0)
            hansu /= 2;
        else
            hansu = (hansu+1)/2;

            cnt++;
    }

}