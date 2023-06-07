#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    float res = 0;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    float tmp = n * 0.15;

    tmp = round(tmp);
    sort(v.begin(), v.end());

    for (int i = tmp; i < n - tmp; i++)
        res += v[i];
    res /= (n - tmp * 2);
    res = round(res);

    cout << res << endl;
    return 0;

}

