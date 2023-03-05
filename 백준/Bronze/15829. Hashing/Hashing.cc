/**
 * 15829. Hashing
 */

#include <iostream>
using namespace std;

int L;
long long ans;
int r = 31, M = 1234567891;

int pow(const int& a, const int& b) {
    int result = 1;
    for (int i = 0; i < b; i++)
        result = (result * a) % M;

    return result;
}

int hashing(const int& idx, const int& a) {
    return (a*pow(r, idx)) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L;
    for (int i = 0; i < L; i++) {
        char target; cin >> target;
        ans += hashing(i, (int)target-96);
    }

    ans %= M;
    cout << ans << "\n";
    return 0;
}