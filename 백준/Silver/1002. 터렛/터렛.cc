#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;

    while(T--) {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        if(x1==x2 && y1==y2) {
            if(r1==r2) cout << "-1\n";
            else cout << "0\n";
            continue;
        }

        if(dist<r1+r2 && dist>abs(r1-r2)) cout << "2\n";
        else if(dist==r1+r2 || dist==abs(r1-r2))cout << "1\n";
        else cout << "0\n";
    }
}