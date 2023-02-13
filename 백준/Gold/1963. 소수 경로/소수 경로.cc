/**
* 1963. 소수 경로
*/

#include <iostream>
#include <deque>
using namespace std;

int T, from, to;
bool isPrime[10000];
bool visited[10000];
deque<pair<int, int>> deq;

int makeNum(int a, int b, int c, int d) {
    return (1000*a) + (100*b) + (10*c) + d;
}

int thsn(int a) {
    return a/1000;
}

int hndr(int a) {
    return (a%1000)/100;
}

int ten(int a) {
    return (a%100)/10;
}

int one(int a) {
    return a%10;
}

void init() {

    isPrime[1] = false;
    for (int i = 2; i < 10000; i++) isPrime[i] = true;

    for (int i = 2; i*i < 10000; i++) {
        if(!isPrime[i]) continue;

        for (int j = 2*i; j < 10000; j+=i)
            isPrime[j] = false;
    }
}

void bfs() {
    while(!deq.empty()) {
        int n = deq.front().first;
        int cnt = deq.front().second;
        visited[n] = true;
        deq.pop_front();

        if (n == to) {
            cout << cnt << "\n";
            return;
        }

        int a = thsn(n), b = hndr(n), c = ten(n), d = one(n);

        for (int i = 1; i <= 9; i++) {
            int target = makeNum(i, b, c, d);
            if(isPrime[target] && !visited[target])
                deq.push_back(make_pair(target, cnt+1));
        }

        for (int i = 0; i <= 9; i++) {
            int target = makeNum(a, i, c, d);
            if(isPrime[target] && !visited[target])
                deq.push_back(make_pair(target, cnt+1));
        }

        for (int i = 0; i <= 9; i++) {
            int target = makeNum(a, b, i, d);
            if(isPrime[target] && !visited[target])
                deq.push_back(make_pair(target, cnt+1));
        }

        for (int i = 0; i <= 9; i++) {
            int target = makeNum(a, b, c, i);
            if(isPrime[target] && !visited[target])
                deq.push_back(make_pair(target, cnt+1));
        }
    }
    cout << "Impossible\n";
}

int main() {
    init();

    cin >> T;
    while(T--) {
        for (int i = 1; i < 10000; i++) visited[i] = false;
        deq.clear();

        cin >> from >> to;
        deq.push_back(make_pair(from, 0));
        bfs();
    }
}