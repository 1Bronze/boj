/**
 * 1038. 감소하는 수
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 9; i++) v.push_back(to_string(i));

    int pos = 0, npos, cnt = 1;
    while(cnt<=9) {
        npos = v.size();
        for (int i = 1; i <= 9; i++) {
            for(int j=pos; j<npos; j++) {
                int n = v[j][0] - '0';
                if(i>n) v.push_back(to_string(i) + v[j]);
            }
        }
        pos = npos;
        cnt++;
    }

    cin >> N;
    if(N>=v.size()) cout << "-1";
    else cout << v[N];
}