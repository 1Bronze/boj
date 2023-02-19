/**
 * 10818. 최소, 최대
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000000];
int minimum=1000000, maximum=-1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        minimum = min(minimum, arr[i]);
        maximum = max(maximum, arr[i]);
    }

    cout << minimum << " " << maximum;

    return 0;
}