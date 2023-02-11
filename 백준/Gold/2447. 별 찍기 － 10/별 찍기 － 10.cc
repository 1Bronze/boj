/**
* 2447. 별 찍기 - 10
*/

#include <iostream>

using namespace std;

int nextY, nextX, nextSize;

void star(int y, int x, int size) {

    if (size == 3){
        if(y == 2 && x == 2) printf(" ");
        else printf("*");
        return;
    }

    else {
        if (y > size/3 && y <= 2*size/3 && x > size/3 && x <= 2*size/3) // 가운데 위치한 경우 -> 공백 출력
            printf(" ");
        else { // 가운데 위치하지 않은 경우 -> 더 작은 구조로 쪼개서 확인
            nextSize = size/3;
            nextY = y % nextSize; if(!nextY) nextY++;
            nextX = x % nextSize; if(!nextX) nextX++;
            star(nextY, nextX, nextSize);
        }
    }
}

int main() {
    int num; scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++)
            star(i, j, num);
        printf("\n");
    }
}