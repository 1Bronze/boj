#include <iostream>
using namespace std;

int getTwoNum(int n) {
    int result = 0;
    
    for(long long i=2; i<=n; i*=2)
        result += n/i;
        
    return result;
}

int getFiveNum(int n) {
    int result = 0;
    
    for(long long i=5; i<=n; i*=5)
        result += n/i;
        
    return result;
}

int main() {
    int n, m; 
    cin >> n >> m;
    
    int twoNum = getTwoNum(n)-getTwoNum(n-m)-getTwoNum(m);
    int fiveNum = getFiveNum(n)-getFiveNum(n-m)-getFiveNum(m);
    
    int result = (twoNum>fiveNum) ? fiveNum:twoNum;
    cout << result;
    
    return 0;
}
