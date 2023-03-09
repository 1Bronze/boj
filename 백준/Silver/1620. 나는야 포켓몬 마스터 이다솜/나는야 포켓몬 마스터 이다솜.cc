/**
 * 1620. 나는야 포켓몬 마스터 이다솜
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N, M;
unordered_map<int, string> m1;
unordered_map<string, int> m2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string pokemon; cin >> pokemon;
        m1[i] = pokemon;
        m2[pokemon] = i;
    }
    for (int i = 1; i <= M; i++) {
        string ans; cin >> ans;
        try {
            int n = stoi(ans);
            auto item = m1.find(n);
            cout << item->second << "\n";
        } catch(invalid_argument&) {
            auto item = m2.find(ans);
            cout << item->second << "\n";
        }
    }

    return 0;
}