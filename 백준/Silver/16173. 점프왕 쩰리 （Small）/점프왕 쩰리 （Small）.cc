#include <iostream>
using namespace std;

int N;
int arr[4][4];
bool visited[4][4];

int dy[2] = {0, 1};
int dx[2] = {1, 0};

bool isInRange(int y, int x) {
    if(y>=1 && y<=3 && x>=1 && x<=3) return true;
    return false;
}

void print() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(int y, int x) {
    visited[y][x] = true;
    // print();

    int ny, nx;
    for(int i=0; i<2; i++) {
        ny = y + arr[y][x] * dy[i];
        nx = x + arr[y][x] * dx[i];
        if(!isInRange(ny, nx)) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(1,1);
    if(visited[N][N]) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}