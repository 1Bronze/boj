#include <cstdio>
#include <algorithm>

int arr[100000];

int main() {
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    
    std::sort(arr, arr+N);
    
    int M; scanf("%d", &M);
    
    int target;
    for(int i=0; i<M; i++) {
        scanf("%d", &target);
        
        int l = 0, r = N-1;
        while(1) {
            
            if(target<arr[(l+r)/2]) {
                r = (l+r)/2 - 1;
            } else if(target>arr[(l+r)/2]) {
                l = (l+r)/2 + 1;
            } else {
                printf("1\n");
                break;
            } 
            
            if(l>r) {
                printf("0\n");
                break;
            }
        }
    }
}