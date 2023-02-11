/**
* 11729. 하노이 탑 이동 순서
*/

#include <iostream>

using namespace std;

int K;

int getRes(int a, int b) {
    if(a == 1 && b == 2) return 3;
    if(a == 1 && b == 3) return 2;
    if(a == 2 && b == 1) return 3;
    if(a == 2 && b == 3) return 1;
    if(a == 3 && b == 1) return 2;
    if(a == 3 && b == 2) return 1;
}

void move(int n, int from, int to) {
    int target = getRes(from, to);

    if(n==1) printf("%d %d\n", from, to);
    else {
        move(n - 1, from, target);
        printf("%d %d\n", from, to);
        move(n-1, target, to);
    }
}

int main() {
    cin >> K;
    cout << (1<<K) -1 << "\n";
    move(K, 1, 3);
}