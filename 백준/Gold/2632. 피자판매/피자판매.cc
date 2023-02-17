/**
* 2632. 피자판매
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num, m, n;
int pizzaA[1000], pizzaB[1000];
vector<int> A;
vector<int> B;
long long result;

bool compare(int a, int b) {
    return (a>b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> pizzaA[i];
    for (int i = 0; i < n; i++) cin >> pizzaB[i];

    // 피자 A에서 나올 수 있는 경우의 수
    for(int len=1; len<=m; len++) {
        int start = 0, end = len-1, sum = 0;

        if(len==m) {
            for (int i = start; i <= end; i++) sum += pizzaA[i];
            A.push_back(sum);
            if(sum==num) result++;
            continue;
        }

        while(start<m) {
            if(start==0)
                for (int i = start; i <= end; i++) sum += pizzaA[i];
            else sum = sum - pizzaA[start-1] + pizzaA[end%m];

            A.push_back(sum);
            if(sum==num) result++;
            start++; end++;
        }
    }

    // 피자 B에서 나올 수 있는 경우의 수
    for(int len=1; len<=n; len++) {
        int start = 0, end = len-1, sum = 0;

        if(len==n) {
            for (int i = start; i <= end; i++) sum += pizzaB[i];
            B.push_back(sum);
            if(sum==num) result++;
            continue;
        }

        while(start<n) {
            if(start==0)
                for (int i = start; i <= end; i++) sum += pizzaB[i];
            else sum = sum - pizzaB[start-1] + pizzaB[end%n];
            B.push_back(sum);
            if(sum==num) result++;
            start++; end++;
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    // 피자 A + 피자 B에서 나올 수 있는 경우의 수
    int a = 0, b = 0;
    while(a<A.size() && b<B.size()) {

        if(A[a]+B[b]<num) a++;
        else if(A[a]+B[b]>num) b++;
        else {
            long long aCnt = 1, bCnt = 1;
            a++; b++;

            while(a<A.size() && A[a]==A[a-1]) {
                aCnt++; a++;
            }
            while(b<B.size() && B[b]==B[b-1]) {
                bCnt++; b++;
            }

            result += aCnt * bCnt;
        }
    }

    cout << result;
}