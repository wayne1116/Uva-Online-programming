#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a=0;
	while(scanf("%lld", &a)!=EOF){
		printf("%lld\n", a*a*(a+1)*(a+1)/4);
	}
	return 0;
}
