#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {

    vector<int> parent;

    DisjointSet(int n): parent(n+1) {
        for (int i = 0; i < n+1; i++)
            parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(u > v) parent[u] = v;
        else parent[v] = u;
    }
};

int main() {

    int N, M, K;
    cin >> N >> M;

    DisjointSet sets(N);
    vector<int> party[M];

    cin >> K;
    for (int i = 0; i < K; i++) {
        int tmp; cin >> tmp;
        sets.parent[tmp] = 0;
    }

    for (int i = 0; i < M; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            int tmp; cin >> tmp;
            party[i].push_back(tmp);
        }
        for (int j = 1; j < party[i].size(); j++)
            sets.merge(party[i][0], party[i][j]);
    }


    int result = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < party[i].size(); j++) {
            if (sets.find(party[i][j]) == 0) {
                result--;
                break;
            }
        }
    }

    cout << result;
}