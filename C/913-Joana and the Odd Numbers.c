#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a, temp, result;
	while(scanf("%ld",&a)!=EOF){
		temp=(1+a)*(1+a)/2-1;
		result=temp+temp-2+temp-4;
		printf("%ld\n", result); 
	}
	return 0;
}
