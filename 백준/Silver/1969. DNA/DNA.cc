#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int cnt = 0, length = 0;

    string ans;

    cin >> cnt >> length;

    int distance = cnt*length;

    string dnaList[1000];
    for(int i = 0; i < cnt; i++) // DNA 입력받고
        cin >> dnaList[i];

    for (int i = 0; i < length; i++) {
        int a = 0, t = 0, g = 0, c = 0;

        for (int j = 0; j < cnt; j++) { // 각 자리마다 ATGC의 개수를 세고
            switch (dnaList[j][i]) {
                case 'A': a++; break;
                case 'T': t++; break;
                case 'G': g++; break;
                case 'C': c++; break;
            }
        }

        if(a>=t && a>=g && a>=c) {// 제일 많이 나온 염기로 설정
            ans += 'A';
            distance -= a;
        } else if(c>=a && c>=t && c>=g) {
            ans += 'C';
            distance -= c;
        } else if(g>=a && g>=t && g>=c) {
            ans += 'G';
            distance -= g;
        } else {
            ans += 'T';
            distance -= t;
        }
    }

    cout << ans << "\n" << distance;
}