#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int a, n, i;
	int location[100001], num[100001], ans[100001];
	scanf("%d",&a);
	while(a--){
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%d",&num[i]);
			location[num[i]]=0;
		} 
		ans[0]=0;
		location[num[0]]=1;
		for(i=1; i<n; i++){
			if(location[num[i]]==0) ans[i]=ans[i-1];
			else{
				ans[i]=max(ans[i-1],ans[location[num[i]]]+1);
			}
			location[num[i]]=i;
		}
		printf("%d\n", ans[n-1]);
	}
	return 0;
}
