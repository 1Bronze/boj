#include <iostream>

using namespace std;

int N;
int arr[10001];

bool compare(const int &a, const int &b) {
    return a < b;
}

int main() {
    scanf("%d", &N);

    int tmp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        arr[tmp]++;
    }
    
    for (int i = 1; i < 10001; i++) {
        while (arr[i]--) {
            printf("%d\n", i);
        }
    }
}
