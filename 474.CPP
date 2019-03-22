#include<stdio.h>
#include<stdlib.h>
double result[1000001];
int exp[1000001];
int main()
{
	int i=0, a=0;
	double temp;
	result[1]=5000; exp[1]=-1;
	for(i=2; i<=1000000; i++){
		temp=result[i-1]/2;
		exp[i]=exp[i-1];
		if(temp<1000){
			temp*=10;
			--exp[i];
		}
		result[i]=temp;
	}
	while(scanf("%d",&a)!=EOF){
		printf("2^-%d = %.3fe%d\n", a, result[a]/1000.0,exp[a]);
	}
	return 0;
}
