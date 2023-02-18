/**
* 10953. A+B - 6
*/

#include <iostream>
#include <iomanip>
using namespace std;

int T, A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> A;
        cin.ignore();
        cin >> B;
        cout << A + B << "\n";
    }

    return 0;
}