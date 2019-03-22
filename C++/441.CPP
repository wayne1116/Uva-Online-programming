#include<stdio.h>
#include<stdlib.h>
int n=0;
void rec(int number[], int k, int result[], int step)
{
	int i=0;
	if(n-k<6-step) return;
	else if(step==6){
		printf("%d", result[0]);
		for(i=1; i<6; i++) printf(" %d", result[i]);
		printf("\n");
		return ;
	}
	for(i=k; i<n; i++){
		result[step]=number[i];
		rec(number,i+1,result,step+1);
	}
}
int main()
{
	int i=0, number[32], result[8]={0}, j=0;
	while(scanf("%d",&n)&&n){
		if(j++>0) printf("\n");
		for(i=0; i<n; i++) scanf("%d",&number[i]);
		rec(number,0, result,0);
	}
	return 0;
}
