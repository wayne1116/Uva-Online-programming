#include<stdio.h>
#include<stdlib.h>
short dp[10001][101];
int main()
{
    int a, i, j;
    int n, divide, number, mod;

    scanf("%d", &a);
    while(a--){
        scanf("%d %d", &n, &divide);
        memset(dp, 0, sizeof(dp));
        
        scanf("%d", &number);
        mod=number%divide;
        dp[0][(mod+divide)%divide]=1;
        for(i=1; i<n; i++){
            scanf("%d", &number);
            mod=number%divide;
            for(j=0; j<divide; j++){
                if(dp[i-1][j]){
                    dp[i][(j+mod+divide)%divide]=1;
                    dp[i][(j-mod+divide)%divide]=1;
                }
            }
        }
        if(dp[n-1][0]) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
