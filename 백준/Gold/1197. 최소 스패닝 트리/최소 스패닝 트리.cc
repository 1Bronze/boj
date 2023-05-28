#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int n): parent(n), rank(n, 1) {
    for(int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int u) const {
    if(u == parent[u]) return u;
    return find(parent[u]);
  }

  void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

int main() {
    
	int V, E; 
	cin >> V >> E;
    
    DisjointSet sets(V+1);
    
	int result = 0; 
	vector<pair<int, pair<int, int>>> v; 
	for (int i = 0; i < E; i++) {
		int from, to, cost; 
		cin >> from >> to >> cost; 
		v.push_back({ cost,{from,to} }); 
	}
    
	sort(v.begin(), v.end()); 
    
	for (int i = 1; i <= V; i++) sets.parent[i] = i; 
	for (int i = 0; i < v.size(); i++) {
		if (sets.find(v[i].second.first) != sets.find(v[i].second.second)) {
			sets.merge(v[i].second.first, v[i].second.second); 
			result += v[i].first; 
		}
	}
	cout << result; 
}