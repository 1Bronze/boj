#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string,int> m;
int n, cnt ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while(n--){
        string bookName;
        cin >> bookName;
        m[bookName]++;
    }
    
    for(auto p : m) cnt = max(cnt, p.second);
    for(auto p : m){
        if(p.second == cnt){
            cout << p.first; 
            return 0;
        }
    }
    
}