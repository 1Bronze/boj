/*
 *
 * 2 3 5 7 11 13 17 19 23 29 31 37 41
 */

#include<iostream>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[4000001];
vector<int> prime;
int N, ans;

void init() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;

    for(long long i=2; i*i<=4000000; i++) {
        if(!isPrime[i]) continue;

        for (int j = 2*i; j <= 4000000; j+=i) isPrime[j] = false;
    }

    for (int i = 283140; i <= prime.size(); i++) {
        cout << prime[i] << " ";
    }

    for (int i = 1; i <= 4000000; i++)
        if(isPrime[i]) prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    cin >> N;

    int start = 0, end = 0, sum = prime[0];

    while(start<=end && end<prime.size() && prime[start]<=N) {
        if(sum==N) {
            ans++;
            sum += prime[++end];
            sum -= prime[start++];
        }
        else if(sum<N) sum += prime[++end];
        else sum -= prime[start++];
    }

    cout << ans;
}