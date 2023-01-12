#include <iostream>
#include <string>
using namespace std;

int N; string s; int sum;

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> s;
        
        int score = 0;
        for(int j=0; j<s.length(); j++) {
            if(s[j]=='O') score++;
            else score=0;
            sum+=score;
        }
        
        cout << sum << "\n";
        sum = 0;
    }
}