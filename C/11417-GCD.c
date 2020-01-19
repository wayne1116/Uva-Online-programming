#include<stdio.h>
#include<stdlib.h>
int value[501][501];
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
int main()
{
    int N;
    int G;
    int i, j;
    int tmp;
    while(scanf("%d", &N)!=EOF){
        if(N==0) break;
        for(i=0; i<=N; i++){
            for(j=0; j<=N; j++) value[i][j]=-1;
        }
        G=0;
        for(i=1; i<N; i++){
            for(j=i+1; j<=N; j++){
                if(value[i][j]!=-1) tmp+=value[i][j];
                else{
                    tmp=gcd(i, j);
                    value[i][j]=value[j][i]=tmp;
                    G+=tmp;
                }    
            }
        }
        printf("%d\n", G);
    }
    return 0;
}
