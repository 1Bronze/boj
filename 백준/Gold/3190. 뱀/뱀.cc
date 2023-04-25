/**
 * 3190. 뱀
 */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

#define MAX 101

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int N, K, L;
int arr[MAX][MAX];
deque<pair<int, int>> snake;
set<pair<int, int>> apple;
queue<pair<int, char>> q;
int direction = RIGHT;
int T = 0;


void input() {
    cin >> N >> K;

    snake.push_back({1, 1});
    arr[1][1] = 1;
    for (int i = 1; i <= K; i++) {
        int y, x;
        cin >> y >> x;
        apple.insert({y, x});
    }
    cin >> L;
    for (int i = 1; i <= L; i++) {
        int t;
        char d;
        cin >> t >> d;
        q.push({t, d});
    }
    q.push({0, 'A'});
}

void check(int d) {
    int y = snake.front().first;
    int x = snake.front().second;
    if(d==UP) {
        if(y==1 || arr[y-1][x]==1) {
            cout << T+1 << "\n";
            exit(0);
        }
    } else if(d==RIGHT) {
        if(x==N || arr[y][x+1]==1) {
            cout << T+1 << "\n";
            exit(0);
        }
    } else if(d==DOWN) {
        if(y==N || arr[y+1][x]==1) {
            cout << T+1 << "\n";
            exit(0);
        }
    } else if(d==LEFT) {
        if(x==1 || arr[y][x-1]==1) {
            cout << T+1 << "\n";
            exit(0);
        }
    }
}

void go(int d) {
    if(T==12) {
        int here;
    }

    check(d);
    int y = snake.front().first;
    int x = snake.front().second;
    if(d==UP) {
        arr[y-1][x] = 1;
        snake.push_front({y-1, x});
    } else if(d==RIGHT) {
        arr[y][x+1] = 1;
        snake.push_front({y, x+1});
    } else if(d==DOWN) {
        arr[y+1][x] = 1;
        snake.push_front({y+1, x});
    } else if(d==LEFT) {
        arr[y][x-1] = 1;
        snake.push_front({y, x-1});
    }

    if(apple.find(snake.front()) == apple.end()) {
        int tailY = snake.back().first;
        int tailX = snake.back().second;
        if(snake.front().first!=tailY || snake.front().second!=tailX) arr[tailY][tailX] = 0;
        snake.pop_back();
    } else {
        apple.erase(snake.front());
    }

    T++;
}

void start() {
    int nextDirection;

    int t = q.front().first;
    char tmp = q.front().second;
    q.pop();

    if(tmp=='L') nextDirection = (direction>0) ? direction-1 : direction+3;
    else nextDirection = (direction<3) ? direction+1 : direction-3;

    while(t!=T) go(direction);

    direction = nextDirection;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    while(!q.empty()) start();
    cout << T+1 << "\n";
}