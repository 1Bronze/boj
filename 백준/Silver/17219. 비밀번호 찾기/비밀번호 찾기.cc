/**
 * 17219. 비밀번호 찾기
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> map;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string domain, pw;
        cin >> domain >> pw;

        map.insert({domain, pw});
    }

    for (int i = 1; i <= M; i++) {
        string domain;
        cin >> domain;
        cout << map.at(domain) << "\n";
    }
}