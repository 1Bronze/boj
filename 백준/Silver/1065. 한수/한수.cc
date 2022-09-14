#include <iostream>
using namespace std;

int main() {
    int n = 0, count = 0;
    cin >> n;

    if(n==1000) // 1000은 999로 계산 (한수 개수는 1000과 999가 동일)
        n -= 1;

    if(n/100 == 0) // 두자리 한수의 개수
        count += n;
    else {
        count += 99;

        for(int i=100; i<n+1; i++) { // 세자리 한수의 개수
            int firstDigit = i / 100;
            int secondDigit = (i - (i / 100 * 100)) / 10;
            int thirdDigit = i % 10;

            if(secondDigit*2 == firstDigit+thirdDigit)
                count += 1;
        }
    }

    cout << count;
}