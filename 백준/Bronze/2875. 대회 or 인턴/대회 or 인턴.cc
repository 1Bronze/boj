/**
* 2875. 대회 or 인턴
*/

#include <iostream>
using namespace std;

int N, M, K;

int main() {
    cin >> N >> M >> K;

    while (K--) {
        if (N >= 2 * M) N--;
        else M--;
    }

    if (N >= 2 * M) {
        cout << M;
    } else {
        cout << N / 2;
    }
}