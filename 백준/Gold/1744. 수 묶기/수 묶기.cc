/**
* 1744. 수 묶기
 *
 * 음수를 묶는 우선순위
 *  (1) 음수 - 음수 (큰 숫자끼리)
 *  (2) 음수 - 0
 *  (3) 묶지 않음
 *
 * 양수를 묶는 우선순위
 *  (1) 양수 - 양수
 *  (2) 묶지 않음
*/

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N;
deque<int> positive;
deque<int> negative;
int zeroCnt = 0, sum = 0;

int main() {
    cin >> N;

    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        if(n>0) positive.push_back(n);
        else if(n<0) negative.push_back(n);
        else zeroCnt++;
    }

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    while(negative.size()>1) {
        int a = negative.front();
        negative.pop_front();
        int b = negative.front();
        negative.pop_front();
        sum += a*b;
    }

    if(negative.size()==1) {
        if(zeroCnt>=1) {
            negative.pop_front();
            zeroCnt--;
        } else {
            sum += negative.front();
            negative.pop_front();
        }
    }

    while(positive.size()>1) {
        int a = positive.back();
        positive.pop_back();
        int b = positive.back();
        positive.pop_back();

        if(a==1 || b==1) {
            sum += a;
            sum += b;
        } else {
            sum += a * b;
        }
    }

    if(positive.size()==1) {
        sum += positive.back();
        positive.pop_back();
    }

    cout << sum;
}