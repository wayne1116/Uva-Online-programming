#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
int num[32], aver=0, count=0, n=0;
void rec(int result, int step)
{
	if(result>=aver) return;
	else if(step==n){
		if(result+num[0]>=aver) count++;
		return;
	}
	rec(result+num[step], step+1);
	rec(result,step+1);
}
int main()
{
	int a=0, sum=0, i=0, temp=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&n); sum=0;
 		for(i=0; i<n; i++){
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		aver=(sum%2==0)?(sum/2):(sum+1)/2;
		for(i=0; i<n; i++){
			count=0;
			swap(num[0],num[i],temp);
			rec(0,1);
			swap(num[0],num[i],temp);
			printf("party %d has power index %d\n", i+1, count);
		}
		printf("\n");
	}
	return 0;
}
