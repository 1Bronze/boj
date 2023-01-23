#include <iostream>
using namespace std;

int N;
int num, result;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> num;
        
        if(num==2) result++;
        
        for(int j=2; j<num; j++) {
            if(num%j==0) break;
            if(j==num-1) result++;
        }
    }
    
    cout << result;
}
