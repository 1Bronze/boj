#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    int n = 0;
    
    cin >> word;
    n = word.length();
    
    for(int i = 0; i < word.length(); i++) {
        if( (word[i]=='c' && word[i+1]=='=')
           || (word[i]=='c' && word[i+1]=='-')
           || (word[i]=='d' && word[i+1]=='z' && word[i+2]=='=')
           || (word[i]=='d' && word[i+1]=='-')
           || (word[i]=='l' && word[i+1]=='j')
           || (word[i]=='n' && word[i+1]=='j')
           || (word[i]=='s' && word[i+1]=='=')
           || (word[i]=='z' && word[i+1]=='=') ) {
            n -= 1;
        }
    }
    
    cout << n;
    
}