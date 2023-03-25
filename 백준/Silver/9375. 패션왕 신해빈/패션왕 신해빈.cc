/**
 * 9375. 패션왕 신해빈
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int T, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        map<string, int> m;

        cin >> n;
        string name, category;

        while (n--) {
            cin >> name >> category;
            if(m.find(category)!=m.end()) m[category]++;
            else m.insert({category, 1});
        }

        int result = 1;
        for (auto i: m) result *= (i.second+1);
        if(m.empty()) cout << "0\n";
        else cout << result-1 << "\n";
    }

    return 0;
}