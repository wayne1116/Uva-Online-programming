#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long a, temp, count, differ;
	while(scanf("%lld",&a)!=EOF){
		count=(-1+sqrt(1+8*(a-1)))/2;
		temp=(count+1)*count/2+1;
		differ=a-temp;
		printf("%lld/%lld\n",count-differ+1,differ+1);
	}
	return 0;
}
