/**
* 1759. 암호 만들기
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
string str;

bool isVowel(const char& c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

void dfs(char target, string s, int c, int v) {
    int idx = str.find(target);

    if(s.length()==L) {
        if(c>=2 && v>=1) cout << s << "\n";
        return;
    }

    for (int i = idx+1; i < C; i++) {
        string tmp = s;
        tmp.push_back(str[i]);

        if(isVowel(str[i])) dfs(str[i], tmp, c, v+1);
        else dfs(str[i], tmp, c+1, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    for (int i=0; i<C; i++) {
        char tmp; cin >> tmp;
        str += tmp;
    }
    sort(str.begin(), str.end());

    for(int i=0; i<C; i++) {
        string tmp = ""; tmp.push_back(str[i]);
        if(isVowel(str[i])) dfs(str[i], tmp, 0, 1);
        else dfs(str[i], tmp, 1, 0);
    }
}