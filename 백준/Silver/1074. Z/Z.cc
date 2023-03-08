/**
 * 1074. Z
 */

#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

int recur(int y, int x, int l) {

    if(l==1) return 2*y + x;

    int cnt = 0;
    if(y<l && x<l) cnt += 0;
    else if(y<l && x>=l) cnt += l*l;
    else if(y>=l && x<l) cnt += l*l*2;
    else cnt += l*l*3;

    return cnt + recur(y%l, x%l, l/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    int len = pow(2, N - 1);
    cout << recur(r, c, len);
    
    return 0;
}