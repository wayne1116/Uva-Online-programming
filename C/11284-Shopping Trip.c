#include<stdio.h>
#include<stdlib.h>
long long int dp[16][1<<15];
long long int min(long long int a, long long int b){ return a>b?b:a;}
long long int max(long long int a, long long int b){ return a>b?a:b;}

int main()
{
    int a, n, edge, i, j, k;
    int v1, v2;
    int count, temp, mask;
    int person[16];
    long long int dis[64][64];
    long long int cost1, cost2; 
    long long int sell[64];
    long long int result=0;

    scanf("%d", &a);
    while(a-->0) {
        scanf("%d %d", &n, &edge);
        
        for(i=0; i<=n; i++){
            sell[i]=0;
            for(j=0; j<=n; j++){
                dis[i][j]=1000000;
            }
            dis[i][i]=0;
        }

        for(i=0; i<edge; i++) {
            scanf("%d %d", &v1, &v2);
            scanf("%lld.%lld", &cost1, &cost2);
            dis[v2][v1]=dis[v1][v2]=min(dis[v1][v2], cost1*100+cost2);
        }

        scanf("%d", &temp);
        count=0;
        for(i=0; i<temp; i++) {
            scanf("%d", &v1);
            if(sell[v1]==0)
                person[count++]=v1;
            scanf("%lld.%lld", &cost1, &cost2);
            sell[v1]+=cost1*100+cost2;
        }

        for(k=0; k<=n; k++) {
            for(i=0; i<=n; i++) {
                for(j=0; j<=n; j++) {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                        dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }

        mask=1<<count;
        for(i=0; i<count; i++) {
            for(j=0; j<mask; j++)
                dp[i][j]=-1000000;
        }

        result=-1000000;
        for(i=1; i<mask; i++) {
            for(j=0; j<count; j++) {
                if(i&(1<<j)){
                    if((i^(1<<j))==0)
                        dp[j][i]=sell[person[j]]-2*dis[0][person[j]];
                    else{
                        for(k=0; k<count; k++) {
                            if((i&(1<<j))!=0 && k!=j)
                                dp[j][i]=max(dp[j][i], dp[k][i^(1<<j)]+dis[0][person[k]]-dis[person[k]][person[j]]+sell[person[j]]-dis[0][person[j]]);
                        }
                    }
                    result=max(result, dp[j][i]);
                }
            }
        }

        if(result<=0)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%lld.%02lld\n", result/100, result%100);
    }

    return 0;
}
