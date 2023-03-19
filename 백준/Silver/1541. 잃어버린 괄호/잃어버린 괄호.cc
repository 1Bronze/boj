/**
 * 1541. 잃어버린 괄호
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> v;
int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    int tmp = 0; bool negative = false;
    for (int i = 0; i < s.length(); i++) {
        if(s[i]>=48 && s[i]<58) {
            tmp = 10*tmp + (s[i]-'0');

            if(i==s.length()-1) {
                if(negative) tmp *= -1;
                v.push_back(tmp);
                tmp = 0;
            }
        } else {
            if(negative) tmp *= -1;
            v.push_back(tmp);
            tmp = 0;

            if(s[i]=='-') negative = true;
        }
    }

    for (const auto &i: v) {
//        cout << "> " << i << "\n";
        result += i;
    }

    cout << result;
}