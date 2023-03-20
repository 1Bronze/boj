/**
 * 5525. IOIOI
 */

#include <iostream>
#include <string>
using namespace std;

int N, M;
string s;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string target = "I";
    for (int i = 0; i < N; i++) {
        target += 'O';
        target += 'I';
    }

    cin >> M;
    cin >> s;

    for (int i = 0; i <= M-(2*N+1); i++) {
        bool possible = true;

        if(s[i]=='O') continue;

        for (int j = i; j < i+(2*N+1); j++) {
            char c = s[j];

            if(i%2==0) {
                if(j%2==0 && c=='O') possible = false;
                if(j%2==1 && c=='I') possible = false;
                if(!possible) break;
            } else {
                if(j%2==1 && c=='O') possible = false;
                if(j%2==0 && c=='I') possible = false;
                if(!possible) break;
            }
        }
        if(possible) cnt++;
    }

    cout << cnt;
}