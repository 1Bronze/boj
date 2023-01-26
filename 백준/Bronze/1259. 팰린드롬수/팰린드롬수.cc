#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    
    while(1) {
        cin >> str;
    
        if(str=="0") break;
    
        int len = str.length();
        
        if(len==1) cout << "yes" << "\n";
        
        for(int j=0; j<len/2; j++) {
            if(str[j]!=str[len-1-j]) {
                cout << "no" << "\n";
                break;
            }
            if(j==len/2-1) cout << "yes" << "\n";
        }
    }
    
    return 0;
}