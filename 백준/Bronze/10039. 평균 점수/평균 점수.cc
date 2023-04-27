#include <iostream>
using namespace std;

int result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int score;
    for(int i=0; i<5; i++) {
        cin >> score;
        result += (score>40) ? score:40;
    }
    
    cout << result/5;
}