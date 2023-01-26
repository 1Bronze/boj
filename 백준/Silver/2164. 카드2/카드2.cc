#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main() {
    int N; cin >> N;
    // back = top, front = bottom
    for(int i=1; i<=N; i++) d.push_front(i);

    while(1) {
        if(d.size()==1) break;

        d.pop_back();
        d.push_front(d.back());
        d.pop_back();
    }

    cout << d.front();
    return 0;
}