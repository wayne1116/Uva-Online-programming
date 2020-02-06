#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))
int main()
{
	int i=0, j=0, k=0, n=0, count=0;
	int x[256], y[256];
	int dis[256][256];
	
	while(scanf("%d",&n)&&n){
		printf("Scenario #%d\n", ++count);
		for(i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
		for(k=0; k<n; k++){                                   /*floyd warshall*/
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j])); 
					/*依題目要求,要找出從Freddy所在的石頭及Fiona所在的石頭間所有路徑中最長跳躍距離為最小*/ 
				}
			}
		}
		printf("Frog Distance = %.3f\n\n", sqrt(dis[0][1]));
	}
	return 0;
}
