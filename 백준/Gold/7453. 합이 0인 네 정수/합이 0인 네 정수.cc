/**
* 7453. 합이 0인 네 정수
 *
 * (A+B)로 나올 수 있는 조합을 AB배열에 저장.
 * (C+D)로 나올 수 있는 조합을 CD배열에 저장.
 *
 * AB 오름차순, CD 내림차순 정렬.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int A[4000], B[4000], C[4000], D[4000];
vector<int> AB, CD;
long long result;

bool compare(int a, int b) {
    return (a>b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++) {
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end(), compare);

    int i = 0, j = 0;
    while(i<AB.size() && j<CD.size()) {
        if(AB[i]+CD[j]>0) j++;
        else if(AB[i]+CD[j]<0) i++;
        else {
            long long iCnt = 1, jCnt = 1;
            i++; j++;

            while(i<AB.size() && AB[i]==AB[i-1]) {
                iCnt++; i++;
            }

            while(j<CD.size() && CD[j]==CD[j-1]) {
                jCnt++; j++;
            }

            result += (jCnt * iCnt);
        }
    }
    cout << result;
}