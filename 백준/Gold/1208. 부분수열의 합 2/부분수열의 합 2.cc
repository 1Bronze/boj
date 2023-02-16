/**
* 1208. 부분수열의 합 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
long long result;
int arr[40];
vector<int> l, r;

void combination(int sum, int k, bool isLeft) {
    int max = (isLeft) ? N/2:N;
    if (k >= max) return;

    sum += arr[k];
    if (sum==S) result++;

    if(isLeft) l.push_back(sum);
    else r.push_back(sum);
    combination(sum-arr[k], k+1, isLeft);
    combination(sum, k+1, isLeft);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    combination(0, 0, true);
    combination(0, N/2, false);

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());

    int i = 0, j = 0;
    while (i<l.size() && j<r.size()) {
        if (l[i] + r[j] == S) {
            long long l_size = 1;
            long long r_size = 1;

            i++; j++;
            while (i<l.size() && l[i]==l[i-1]) {
                l_size++; i++;
            }
            while (j<r.size() && r[j]==r[j-1]) {
                r_size++; j++;
            }

            result += (l_size * r_size);
        }
        else if (l[i] + r[j] < S) i++;
        else j++;
    }



    cout << result;
}