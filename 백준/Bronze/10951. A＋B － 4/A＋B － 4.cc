/**
* 10951. A+B - 4
*/

#include <iostream>
using namespace std;

int T, A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> A >> B;
        if(cin.eof()) break;
        cout << A+B << "\n";
    }

    return 0;
}