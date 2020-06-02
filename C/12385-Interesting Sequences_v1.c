#include<stdio.h>
#include<stdlib.h>
int flag[100001], buf[100001];
int main()
{
	int a, b, n, i, j, k, result=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&n);
		j=0;
		result=0;
		for(i=0; i<100001; i++) flag[i]=buf[i]=0;
		for(i=0; i<n; i++){
			scanf("%d",&b);
			if(flag[b]==0){
				buf[j++]=b;
				flag[b]=1;
			}
			else{
				result++;
				for(k=0; k<j; k++) flag[buf[k]]=0;
				flag[b]=1;
				buf[0]=b;
				j=1;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
