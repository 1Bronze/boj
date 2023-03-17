/**
 * 11655. ROT13
 */

#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        char target = s[i];
        if(target>=65 && target<91)
            target = 65 + (target-65+13)%26;
        if(target>=97 && target<123)
            target = 97 + (target-97+13)%26;

        cout << target;
    }
}