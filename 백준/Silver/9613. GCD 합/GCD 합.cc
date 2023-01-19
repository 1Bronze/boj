#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int T; int N; long sum = 0;
int arr[100];

int getGCD(int a, int b) {
    int mod = a % b;
    
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	
    return b;
}

int main()
{
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        
        for(int j=0; j<N; j++) cin >> arr[j];
        
        for(int k=0; k<N-1; k++) {
            for(int l=k+1; l<N; l++) {
                sum += getGCD(arr[k], arr[l]);
            }
        }
        
        cout << sum << "\n";
        sum = 0;
    }

    return 0;
}
