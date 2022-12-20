  #include <stdio.h>

  int getStarNum(int l, int N) {
    if(l<=N) return l;
    else return 2*N-l;
  }

  int getSpaceNum(int l, int N) {
    return N - getStarNum(l, N);
  }

  int main() {
    int cnt;
    scanf("%d", &cnt);
    for(int i=1; i<=2*cnt-1; i++) {
        for(int j=0; j<getSpaceNum(i, cnt); j++) printf(" ");
        for(int j=0; j<getStarNum(i, cnt); j++) printf("*");
        printf("\n");
    }
  }