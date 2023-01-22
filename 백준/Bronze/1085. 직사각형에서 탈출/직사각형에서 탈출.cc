#include <iostream>
using namespace std;

int x, y, w, h;
int result;

int min(int a, int b) {
    return a<b ? a:b;
}

int main() {
    cin >> x >> y >> w >> h;
    
    result = min(x, y);
    result = min(result, w-x);
    result = min(result, h-y);
    
    cout << result;
}