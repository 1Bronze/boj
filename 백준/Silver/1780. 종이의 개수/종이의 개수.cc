/**
* 1780. 종이의 개수
*/

#include <iostream>
using namespace std;

int N;
int result[3] = {0, };
int arr[3000][3000];
int dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

void cut(int y, int x, int len) {

    bool same = true;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if(arr[y][x] != arr[y+i][x+j]) same = false;
        }
    }

    if(same) {
        int val = arr[y][x];
        if(val==-1) result[0]++;
        else if(val==0) result[1]++;
        else if(val==1) result[2]++;
    } else {
        int nextLen = len/3;

        for (int i = 0; i < 9; i++) {
            cut(y+(nextLen*dy[i]), x+(nextLen*dx[i]), nextLen);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    cut(1, 1, N);

    for (const auto &item: result)
        printf("%d\n", item);

}