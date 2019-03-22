#include<stdio.h>
#include<stdlib.h>
#define max(x,y) ((x)>(y)?(x):(y))
int main()
{
	int n=0, i=0, max=0, num[10001], result[10001];
	while(scanf("%d",&n)&&n){
		for(i=0; i<n; i++) scanf("%d",&num[i]);
		result[0]=num[0];
		for(i=1; i<n; i++) result[i]=max(result[i-1]+num[i],num[i]);
		max=result[0];
		for(i=1; i<n; i++) if(max<result[i]) max=result[i];
		if(max<=0) printf("Losing streak.\n");
		else printf("The maximum winning streak is %d.\n", max);
	}
	return 0;
}
