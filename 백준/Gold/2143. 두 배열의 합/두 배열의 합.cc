/**
* 2143. 두 배열의 합
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, n, m;
int A[1000], B[1000];
vector<int> sumA, sumB;
long long result;

bool compare(int a, int b) {
    return (a>b);
}

//void combinationA(int sum, int idx) {
//    if(idx>=n) return;
//
//    sum += A[idx];
//    sumA.push_back(sum);
//
//    combinationA(sum-A[idx], idx+1);
//    combinationA(sum, idx+1);
//}
//
//void combinationB(int sum, int idx) {
//    if(idx>=n) return;
//
//    sum += B[idx];
//    sumB.push_back(sum);
//
//    combinationB(sum-B[idx], idx+1);
//    combinationB(sum, idx+1);
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> B[i];

//    combinationA(0, 0);
//    combinationB(0, 0);

    for(int len=1; len<=n; len++) {
        int start = 0, end = len-1, sum = 0;

        if(len==n) {
            for (int i = start; i <= end; i++) sum += A[i];
            sumA.push_back(sum);
            continue;
        }

        while(end<n) {
            if(start==0)
                for (int i = start; i <= end; i++) sum += A[i];
            else sum = sum - A[start-1] + A[end];

            sumA.push_back(sum);
            start++; end++;
        }
    }

    for(int len=1; len<=m; len++) {
        int start = 0, end = len-1, sum = 0;

        if(len==m) {
            for (int i = start; i <= end; i++) sum += B[i];
            sumB.push_back(sum);
            continue;
        }

        while(end<m) {
            if(start==0)
                for (int i = start; i <= end; i++) sum += B[i];
            else sum = sum - B[start-1] + B[end];
            sumB.push_back(sum);
            start++; end++;
        }
    }



    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end(), compare);

    int a = 0, b = 0;
    while(a<sumA.size() && b<sumB.size()) {

        if(sumA[a]+sumB[b]<T) a++;
        else if(sumA[a]+sumB[b]>T) b++;
        else {
            long long aCnt = 1, bCnt = 1;
            a++; b++;

            while(a<sumA.size() && sumA[a]==sumA[a-1]) {
                aCnt++; a++;
            }
            while(b<sumB.size() && sumB[b]==sumB[b-1]) {
                bCnt++; b++;
            }

            result += aCnt * bCnt;
        }
    }

    cout <<result;
}