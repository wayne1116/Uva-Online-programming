#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, j=0, n=0, m=0, max=0, sum1=0;
	int result[128][128], sum[128][128];
	
	while(scanf("%d",&a)!=EOF){
		for(i=0; i<=a; i++) result[i][0]=result[0][i]=sum[0][i]=sum[i][0]=0;
		for(i=1; i<=a; i++){
			for(j=1; j<=a; j++) scanf("%d",&result[i][j]);
		}
		for(i=1; i<=a; i++){                                                 //算出(0,0)到(x,y)正方形的值 
			for(j=1; j<=a; j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+result[i][j];
			}
		}
		max=-127;
		for(i=1; i<=a; i++){                                                   //算出 (i,j) 到(x,y) 的長方形值 
			for(j=1; j<=a; j++){
				for(n=1; n<=i; n++){
					for(m=1; m<=j; m++){
						sum1=sum[i][j]-sum[n-1][j]-sum[i][m-1]+sum[n-1][m-1];
						if(sum1>max) max=sum1;
					}
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
