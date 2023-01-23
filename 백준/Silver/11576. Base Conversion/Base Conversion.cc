#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int A, B, len;
int arr[26];
stack<int> result;

int main()
{
    cin >> A >> B;
    cin >> len;
    for(int i=1; i<=len; i++) cin >> arr[i];
    
    int decimal = 0;
    for(int i=1; i<=len; i++) {
        decimal += arr[i] * pow(A, len-i);
    }
    
    while(decimal!=0) {
        result.push(decimal%B);
        decimal /= B;
    }
    
    while(!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
}
