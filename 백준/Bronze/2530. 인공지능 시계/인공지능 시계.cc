#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int h, m, s, d;
    cin >> h >> m >> s >> d;
    cout << (h+(m+(s+d)/60)/60)%24 << " " << (m+(s+d)/60)%60 << " " << (s+d)%60;
    return 0;
}