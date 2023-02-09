#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool arr[1001];

int main() {
    cin >> N >> K;

    for(int i=1; i<=1000; i++) {
        if(i<=N) arr[i] = true;
        else arr[i] = false;
    }

    cout << "<";

    int target = K;
    for(int i=1; i<=N; i++) {
        if(arr[target]) {
            arr[target] = false;
            cout << target;
            if(i!=N) cout << ", ";
        } else {
            for(int j=0; j<K; j++) {
                target++;
                if(target>N) target-=N;
                if(!arr[target]) j--;
            }
            i--;
        }
    }

    cout << ">";
}