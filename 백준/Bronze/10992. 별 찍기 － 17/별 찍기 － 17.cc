 #include <stdio.h>

void drawBorder(int l, int N) {
    if(l==N)
        for(int i=0; i<2*l-1; i++) printf("*");
    else if(l==1) {
        printf("*");
    } else {
        for(int i=0; i<2*l-1; i++) {
            if(i==0 || i==2*l-2) printf("*");
            else printf(" ");
        }
    }
}

 int main() {
    int cnt;
    scanf("%d", &cnt);
    for(int i=1; i<=cnt; i++) {
        for(int j=1; j<=cnt-i; j++) printf(" ");
        drawBorder(i, cnt);
        printf("\n");
    }
  }