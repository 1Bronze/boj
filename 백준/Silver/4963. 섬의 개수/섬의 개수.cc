/**
* 4963 섬의 개수
*/

#include <iostream>
#include <cstring>
using namespace std;

int w, h, result;
int islands[51][51];
int checked[51][51];

int dx[8]={-1,-1,0,1,1, 1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

void search(int y, int x) {

    for (int i = 0; i < 8; i++) {
        int nextX=x+dx[i];
        int nextY=y+dy[i];

        if(nextX<1 || nextY<1 || nextX>w || nextY>h ) continue;

        if(!checked[nextY][nextX]&&islands[nextY][nextX]) {
            checked[nextY][nextX] = true;
            search(nextY,nextX);
        }
    }
}

int main() {
    while(1) {
        result = 0;
        cin >> w >> h;
        if(w==0 && h==0) break;

        memset(islands,0,sizeof(islands));
        memset(checked,false,sizeof(checked));

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> islands[i][j];
            }
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if(!islands[i][j] || checked[i][j]) continue;

                search(i, j);
                result++;
            }
        }

        cout << result << "\n";
    }
}

