#include <iostream>
#include <deque>
using namespace std;

int N, K, result = -1;
bool visited[200002] = {false, };
deque<pair<int, int>> d;

bool validate(int n) {
    return (n>=0 && n<=100000);
}

void bfs() {
    while(1) {
        pair<int, int> target = d.front();
        d.pop_front();
        visited[target.first] = true;

        if(target.first == K) {
            cout << target.second;
            break;
        }

        if(validate(target.first-1) && !visited[target.first-1])
            d.push_back(make_pair(target.first-1, target.second+1));
        if(validate(target.first+1) && !visited[target.first+1])
            d.push_back(make_pair(target.first+1, target.second+1));
        if(validate(2*target.first) && !visited[2*target.first])
            d.push_back(make_pair(2*target.first, target.second+1));
    }
}

int main() {
    cin >> N >> K;

    d.push_back(make_pair(N, 0));
    bfs();
}