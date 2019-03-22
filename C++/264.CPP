#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, n=0, temp=0, number1=0, number2=0;
	while(scanf("%d",&a)!=EOF){
		n=1;
		temp=1;
		while(temp<a) temp+=++n;
		number1=1+temp-a;
		number2=n-temp+a;
		printf("TERM %d IS ", a);
		if(n%2) printf("%d/%d\n", number1, number2);
		else printf("%d/%d\n", number2, number1);
		
	}
	return 0;
}
