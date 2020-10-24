#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a, i;
	int flag=0;
	while(scanf("%lld",&a)&&a){
		flag=0;
		for(i=9; i>=0; i--){
			if((a-i)%9==0){
				if(flag==0){
					flag=1;
					printf("%lld",(a-i)/9*10+i);
				}
				else printf(" %lld",(a-i)/9*10+i);
			}
		}
		printf("\n");
	}
	return 0;
}
