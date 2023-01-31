#include <iostream>
using namespace std;

int T;
int H, W, N;

int main() {
    cin >> T;
    
    for(int i=0; i<T; i++) {
        cin >> H >> W >> N;
        
        int floor = N % H;
        int room = N/H + 1;
        
        if(floor==0) {
            floor = H;
            room -= 1;
        }
        
        cout << floor;
        if(room<10) cout << "0";
        cout << room << "\n";
    }
    
    return 0;
}