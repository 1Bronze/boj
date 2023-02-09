/**
* 11050. 이항 계수 1
*/

#include <cstdio>
using namespace std;

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    int a = 1;

    int tmp = K;
    while(tmp--) {
        a *= N;
        N--;
    }

    if(K==0) a = 1;
    else
        for (int i = K; i >= 1; i--) a /= i;


    printf("%d", a);
}