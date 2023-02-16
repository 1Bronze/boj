#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000];
int N, S;

int main(){
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];
    int start=0, end=0, sum = arr[0], ans = 987654321;
    while(start <= end && end < N){
        if(sum >= S) ans = min(ans, (end-start+1));

        if(sum < S) sum += arr[++end];
        else sum -= arr[start++];
    }
    if(ans == 987654321) cout << "0";
    else cout << ans;
}