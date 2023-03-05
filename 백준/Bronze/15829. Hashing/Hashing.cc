/**
 * 15829. Hashing
 */

#include <iostream>
#include <cmath>
using namespace std;

int L;
int result;

int hashing(const int& idx, const int& a) {
    int r = 31, M = 1234567891;
    return (a*((int)pow(r, idx)))%M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L;
    for (int i = 0; i < L; i++) {
        char target; cin >> target;
        result += hashing(i, (int)target-96);
    }

    cout << result << "\n";
    return 0;
}