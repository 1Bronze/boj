#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<string>

using namespace std;

string Start, End;
set<string> Visit;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input() {
    End = "123456780";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            char Tmp = a + '0';
            Start = Start + Tmp;
        }
    }
}

int BFS() {
    queue<pair<string, int>> Q;
    Q.push(make_pair(Start, 0));
    Visit.insert(Start);

    while (!Q.empty()) {
        string Cur = Q.front().first;
        int Cnt = Q.front().second;
        Q.pop();

        if (Cur == End) return Cnt;

        int Zero = Cur.find('0');
        int x = Zero / 3;
        int y = Zero % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
                string Next = Cur;
                swap(Next[x * 3 + y], Next[nx * 3 + ny]);

                if (Visit.find(Next) == Visit.end()) {
                    Visit.insert(Next);
                    Q.push(make_pair(Next, Cnt + 1));
                }
            }
        }
    }
    return -1;
}

void Solution() {
    cout << BFS() << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}