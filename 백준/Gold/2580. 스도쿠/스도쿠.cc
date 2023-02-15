#include <iostream>
using namespace std;

int sudoku[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int cnt) {
    int y = cnt/9;
    int x = cnt%9;

    if(cnt == 81) {
        print();
        exit(0);
    }

    if(sudoku[y][x]==0) {
        for (int i = 1; i <= 9; i++) {
            if(row[y][i]==false && col[x][i]==false && square[(y/3)*3+(x/3)][i]==false) {
                row[y][i] = true;
                col[x][i] = true;
                square[(y/3)*3+(x/3)][i] = true;
                sudoku[y][x] = i;
                dfs(cnt+1);
                sudoku[y][x] = 0;
                square[(y/3)*3+(x/3)][i] = false;
                col[x][i] = false;
                row[y][i] = false;
            }
        }
    } else dfs(cnt+1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j]!=0) {
                row[i][sudoku[i][j]] = true;
                col[j][sudoku[i][j]] = true;
                square[(i/3)*3+(j/3)][sudoku[i][j]] = true;
            }
        }
    }

    dfs(0);
}