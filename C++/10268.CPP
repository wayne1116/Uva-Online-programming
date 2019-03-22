#include<stdio.h>
#include<stdlib.h>
int num[1000000];
int main()
{
	int x=0, sum=0, temp=0, i=0, coef=0, count=0;
	while(scanf("%d",&x)!=EOF){
		for(count=0; scanf("%d",&num[count++])&& getchar()!='\n';);
		sum=0; coef=1; temp=1;
		for(i=count-2; i>=0; i--, temp*=x, coef++) sum+=num[i]*temp*coef;
		printf("%d\n", sum);
	}
	return 0;
}
