/**
* 10816 숫자 카드
*/

#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;
int N, M, card;

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &card);
        m[card]++;
    };

    scanf("%d", &M);
    for (int i = 1; i <= M; i++) {
        scanf("%d", &card);
        printf("%d ", m[card]);
    }
}
