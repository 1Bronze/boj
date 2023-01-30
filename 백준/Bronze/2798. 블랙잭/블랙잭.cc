#include <iostream>
using namespace std;

int arr[101];
int n, m;

int max(int a, int b) {
    return a>b ? a:b;
}

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> arr[i];

    int result = 0;
    int sum = 0;
    for(int i=1; i<=n-2; i++) {
        for(int j=i+1; j<=n-1; j++) {
            for(int k=j+1; k<=n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if(sum<=m) result = max(result, sum);
            }
        }
    }

    cout << result;
}