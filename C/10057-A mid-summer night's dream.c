#include<stdio.h>
#include<stdlib.h>
int abs(int x)
{
	return x>0?x:-x;
}
int cmp(const void *x, const void *y)
{
	return *(int*)x-*(int*)y;
}
int num[1000001];
int main()
{
	int i=0, n=0, count=0, result=0, sum1=0, sum2=0, middle1, middle2;
	while(scanf("%d",&n)!=EOF){
		for(i=0; i<n; i++) scanf("%d",&num[i]);
		qsort(num, n, sizeof(int), cmp);
		if(n%2==1){
			count=0; result=num[n/2];
			for(i=0; i<n; i++){
				if(num[i]==result) ++count;
			}
			printf("%d %d %d\n", result, count, 1);
		}
		else{
			middle1=num[n/2-1]; middle2=num[n/2];
			sum1=sum2=0;
			for(i=0; i<n; i++){
				sum1+=abs(middle1-num[i]);
				sum2+=abs(middle2-num[i]);
			}
			if(sum1==sum2){
				count=0;
				for(i=0; i<n; i++){
					if(num[i]==middle1 || num[i]==middle2) ++count;
				}
				printf("%d %d %d\n", middle1, count, middle2-middle1+1);
			}
			else if(sum1>sum2){
				count=0;
				for(i=0; i<n; i++){
					if(num[i]==middle2) ++count;
				}
				printf("%d %d %d\n", middle2, count, 1);
			}
			else{
				count=0;
				for(i=0; i<n; i++){
					if(num[i]==middle1) ++count;
				}
				printf("%d %d %d\n", middle1, count, 1);
			}
		}
	}
	return 0;
}
