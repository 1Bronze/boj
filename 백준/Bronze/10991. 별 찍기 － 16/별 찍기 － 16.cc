 #include <stdio.h>

 int main() {
    int cnt;
    scanf("%d", &cnt);
    for(int i=1; i<=cnt; i++) {
        
        bool isStar = true;
        for(int j=1; j<=cnt-i; j++) printf(" ");
        
        for(int j=0; j<2*i-1; j++) {
            if(isStar) {
                printf("*");
                isStar = false;
            } else {
                printf(" ");
                isStar = true;
            }
        }
        printf("\n");
    }
  }