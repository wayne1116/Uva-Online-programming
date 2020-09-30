#include<stdio.h>
#include<stdlib.h>
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a=0, b=0, i=0, n=0, len=0;
	int temp1, temp2;
	int result1, result2;
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&len,&n);
		result1=result2=0;
		for(i=0; i<n; i++){
			scanf("%d",&b);
			temp1=max(b,len-b);
			temp2=min(b,len-b);
			result1=max(result1,temp2);
			result2=max(result2,temp1);
		}
		printf("%d %d\n", result1, result2);
	}
	return 0;
}
