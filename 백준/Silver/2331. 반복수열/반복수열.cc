#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string A; int P;
vector<string> v;

int power(int a, int b) {
    int result = 1;

    for(int i=1; i<=b; i++)
        result *= a;

    return result;
}

int main() {

    cin >> A >> P;
    v.push_back(A);

    while(1) {
        string target = v.back();

        int sum = 0;
        for (int i=0; i<target.length(); i++)
            sum += power(target[i]-'0', P);

        if(find(v.begin(), v.end(), to_string(sum)) == v.end())
            v.push_back(to_string(sum));
        else {
            cout << find(v.begin(), v.end(), to_string(sum)) - v.begin();
            break;
        }
    }
}