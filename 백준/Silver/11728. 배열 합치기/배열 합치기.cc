/**
* 11728. 배열 합치기
*/

#include <cstdio>
using namespace std;

int N, M;
int arrA[1000000];
int arrB[1000000];

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arrA[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &arrB[i]);
    }

    int aIndex = 0, bIndex = 0;
    while (aIndex < N && bIndex < M) {

        if(arrA[aIndex]<arrB[bIndex]) printf("%d ", arrA[aIndex++]);
        else printf("%d ", arrB[bIndex++]);
    }

    while(aIndex >= N && bIndex < M) {
        printf("%d ", arrB[bIndex++]);
    }

    while(bIndex >= M && aIndex < N) {
        printf("%d ", arrA[aIndex++]);
    }
}