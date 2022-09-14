#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int h = 0, m = 0;
    cin >> h >> m;

    if(h==0) {
        h = (m>=45)?h:23;
        m = (m>=45)?(m-45):(m+15);
    } else {
        h = (m>=45)?h:(h-1);
        m = (m>=45)?(m-45):(m+15);
    }

    cout << h << " " << m << endl;
}