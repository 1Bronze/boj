/**
 * 10809. 알파벳 찾기
 */

#include <iostream>
#include <string>
using namespace std;

string s;
int arr[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 26; i++)
        arr[i] = -1;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (arr[(int) s[i] - 97] == -1)
            arr[(int) s[i] - 97] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << " ";
    }
}