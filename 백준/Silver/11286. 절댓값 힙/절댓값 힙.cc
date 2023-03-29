/**
 * 11286. 절댓값 힙
 */

#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(pair<int, bool> a, pair<int, bool> b) {
        if(a.first!=b.first) return (a.first>b.first);
        else return (!a.second && b.second) ? false:true;
    }
};

int N;
priority_queue<pair<int, bool>, vector<pair<int, bool>>, compare> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        int x; cin >> x;
        if(x==0 && pq.empty()) cout << "0\n";
        else if(x==0 && !pq.empty()) {
            int first = pq.top().first;
            bool second = pq.top().second;
            pq.pop();

            if(!second) first*=-1;
            cout << first << "\n";
        }
        else {
            int first = (x>0) ? x:(-1*x);
            bool second = (x>0) ? true:false;
            pq.push({first, second});
        }
    }

    return 0;
}