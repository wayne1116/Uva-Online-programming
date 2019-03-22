#include<stdio.h>
#include<stdlib.h>
double temp[1000000];
int main()
{
	double result=1;
	long long i, a, low, high;
	for(i=1; i<1000000; i++){
		result=result*i;
		if(result<10000) low=i;
		else if(result>6227020800){
			high=i;
			break;
		}
		else temp[i]=result;
	}
	while(scanf("%lld",&a)!=EOF){
		if(a<0 && a%2==-1) printf("Overflow!\n");
		else if(a<0 && a%2==0) printf("Underflow!\n");
		else{
			if(high<=a) printf("Overflow!\n");
			else if(low>=a) printf("Underflow!\n");
			else printf("%.0f\n", temp[a]);
		}
	}
	return 0;
}
