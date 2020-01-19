#include<stdio.h>
#include<stdlib.h>
int num[1024], average, flag[1024];
int cmp(const void *x, const void *y)
{
		return *(int *)x-*(int *)y;
}
int dfs(int sum, int index, int n, int step)
{
		int i=0;
		if(step==3) return 1;         /*when you find three length*/
		for(i=index; i<n; i++){
				if(sum+num[i]<=average && flag[i]){
					flag[i]=0;
					sum+=num[i];
					if(sum==average){
							if(dfs(0,0,n,step+1)) return 1;  /*search the next part*/
							else{
								flag[i]=1;
								sum-=num[i];
							}
					}
					else if(dfs(sum,i+1,n,step)) return 1;  /*search the next length*/
					else{
							flag[i]=1;
							sum-=num[i];
					}
				}
		}
		return 0;
}
int main()
{
		int a=0, n=0, i=0, sum=0;
		scanf("%d", &a);
		while(a--){
				scanf("%d", &n);
				sum=0;
				for(i=0; i<n; i++){
						scanf("%d", &num[i]);
						sum+=num[i];
						flag[i]=1;
				}
				qsort(num,n,sizeof(int),cmp);
				average=sum/4;
				if(sum%4 || num[n-1]>average) printf("no\n");
				else if(dfs(0,0,n,0)) printf("yes\n");
				else printf("no\n");
		}
		return 0;
}
