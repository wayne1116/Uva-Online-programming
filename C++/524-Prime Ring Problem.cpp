#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
int flag[32], flag1[32], result[32], n;
void rec(int step)
{
	int i=0;
	if(step==n){
		if(flag[result[n-1]+result[0]]){ 
			for(i=0; i<n-1; i++) printf("%d ", result[i]);
			printf("%d\n", result[i]);
		} 
	}
	else{
		for(i=2; i<=n; i++){
			if(flag1[i] && flag[result[step-1]+i]){
				flag1[i]=0;
				result[step]=i; 
				rec(step+1);
				flag1[i]=1;
			} 
		}
	}
}
int main()
{
	int i=0, j=0, limit=0, round=0;
	for(i=2; i<32; i++){
		limit=sqrt(i);
		for(j=2; j<=limit; j++){
			if(i%j==0) break;
		} 
		if(j>limit) flag[i]=1;
		else flag[i]=0;
	}
	while(scanf("%d",&n)!=EOF){
		if(round++>0) printf("\n");
		printf("Case %d:\n", round);
		for(i=1; i<=n; i++) flag1[i]=1;
		result[0]=1; j=1; flag1[1]=0;
		rec(j);
	}
	return 0;
}
