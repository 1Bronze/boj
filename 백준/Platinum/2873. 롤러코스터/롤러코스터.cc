#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    
    int** pleasure = new int*[R]; // 2차원 배열 동적 할당
    for (int i = 0; i < R; i++) {
        pleasure[i] = new int[C];
    }
    
    pair<int, int> blank;
    int min = 1001; // 1000 최대
    // 배열 입력 및 가장 작은 값과 그 위치 찾기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> pleasure[i][j];
            if (min > pleasure[i][j] && (i + j) % 2 == 1) {
                min = pleasure[i][j];
                blank.first = i;
                blank.second = j;
            }
        }
    }
    
    string move;
    int i, j;
    if (R % 2 == 1) { // R이 홀수일 때
        for (i = 0; i < R; i++) {
            for (j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    move += 'R'; // 오른쪽 방향
                else
                    move += 'L'; // 왼쪽 방향
            }
            if (i == R - 1)
                break;
            move += 'D'; // 아래쪽 방향
        }
    } else if (C % 2 == 1) { // C가 홀수일 때
        for (i = 0; i < C; i++) {
            for (j = 0; j < R - 1; j++) {
                if (i % 2 == 0)
                    move += 'D'; // 아래쪽 방향
                else
                    move += 'U'; // 위쪽 방향
            }
            if (i == C - 1)
                break;
            move += 'R'; // 오른쪽 방향
        }
    } else { // R, C 모두 짝수일 때
        // 모두 짝수일 때는 모든 칸을 지나갈 수 없음. 무조건 한 칸은 지나가지 않음
        int r, c;
        if (blank.first % 2 == 1)
            r = blank.first - 1; // blank가 있는 윗줄까지
        else
            r = blank.first; // blank가 있는 줄까지
        
        for (i = 0; i < r; i++) { // blank 전
            for (j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    move += 'R';
                else
                    move += 'L';
            }
            move += 'D';
        }
        
        c = blank.second; // blank의 열
        for (i = 0; i < c; i++) { // blank 전
            if (i % 2 == 0)
                move += "DR";
            else
                move += "UR";
        }
        
        for (i = c; i < C - 1; i++) { // blank 후
            if (i % 2 == 0)
                move += "RD";
            else
                move += "RU";
        }
        
        for (i = r + 2; i < R; i++) { // blank 아래
            move += 'D';
            for (j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    move += 'L';
                else
                    move += 'R';
            }
        }
    }
    
    cout << move << endl;
    
    return 0;
}