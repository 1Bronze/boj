#include <iostream>
#include <string>
using namespace std;

int N; 
int cnt; string s;

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> cnt >> s;
        
        for(int j=0; j<s.length(); j++) {
            for(int k=0; k<cnt; k++)
                cout << s[j];
        }
        
        cout << "\n";
    }
    
}