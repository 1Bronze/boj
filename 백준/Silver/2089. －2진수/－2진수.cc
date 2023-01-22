#include <iostream>
#include <stack>
using namespace std;

int num;
stack<int> s;

int main()
{
    cin >> num;
    
    if(num==0) {
        cout << 0; 
        return 0;
    }

    while(num!=0) {
        if(num%-2==0) {
            num = num/-2;
            s.push(0);
        } else {
            num = (num-1)/(-2);
            s.push(1);
        }
    }
    
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    
    return 0;
}