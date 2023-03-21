//3
//3 4 5
//2 2

#include <iostream>
using namespace std;

int N;
int arr[1000001];
int n, m;
long long result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    cin >> n >> m;

    for(int i=1; i<=N; i++) {
        result++;
        arr[i] -= n;

        if(arr[i]>0) {
            if(arr[i]%m!=0) result += (arr[i]/m+1);
            else result += arr[i]/m;
        }
    }

    cout << result;
}