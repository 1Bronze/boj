#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // 0 ->              -
    // 1 ->             - -
    // 2 ->          - -   - -
    // 3 -> - -   - -         - -   - -
    int n;

    while (cin >> n) {

        string cantorSet = "-";
        string blankSet;

        for (int i = 0; i < n; i++) {
            blankSet.clear();

            for (int j = 0; j < pow(3, i); j++)
                blankSet += " ";

            cantorSet = cantorSet + blankSet + cantorSet;
        }

        cout << cantorSet << endl;
    }
}