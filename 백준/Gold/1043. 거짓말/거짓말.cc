/**
 * 1043. 거짓말
 */

#include <iostream>
#include <vector>
using namespace std;

struct DisjointSet {

    vector<int> parent;

    DisjointSet(int n): parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(u < v) parent[v] = u;
        else parent[u] = v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    DisjointSet sets(N+1);

    int K; cin >> K;
    // 진실을 아는 사람은 0 집합으로 분류
    for (int i = 1; i <= K; i++) {
        int tmp; cin >> tmp;
        sets.parent[tmp] = 0;
    }

    vector<vector<int>> party(M);
    // party[i]: i번째 파티의 참가자들을 저장하는 벡터
    for (int i = 0; i < M; i++) {
        int participants; cin >> participants;
        for (int j = 0; j < participants; j++) {
            int target; cin >> target;
            party[i].push_back(target);
        }
        // 같은 파티 참가자는 같은 집합으로 설정
        for (int j = 1; j < participants; j++)
            sets.merge(party[i][0], party[i][j]);
    }

    // 모든 파티에서 거짓말을 할 경우에서 시작
    int answer = M;

    // 각 파티마다 진실을 아는 사람이 있을 경우 거짓말을 할 수 없음.
    // 이 경우 answer--
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < party[i].size(); j++) {
            if(sets.find(party[i][j]) == 0) {
                answer--;
                break;
            }
        }
    }

    cout << answer;
}