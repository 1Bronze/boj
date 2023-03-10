/**
 * 1764. 듣보잡
 */

#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, M;
set<string> unheard;
set<string> unseen;
set<string> both;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string name; cin >> name;
        unheard.insert(name);
    }
    for (int i = 1; i <= M; i++) {
        string name; cin >> name;
        unseen.insert(name);
    }

    for (const auto& i: unheard) {
        if(unseen.find(i)!=unseen.end())
            both.insert(i);
    }
    for (const auto& i: unseen) {
        if(unheard.find(i)!=unheard.end())
            both.insert(i);
    }

    cout << both.size() << "\n";
    for (const auto& i: both) {
        cout << i << "\n";
    }
}