#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long n=0, k=0, i=0, j=0;
	long long temp, temp1, temp2, result, coef, coef1;
	while(scanf("%lld%lld",&n,&k)!=EOF){
		temp=n; result=1;
		for(i=0; i<k; i++){
			scanf("%lld", &coef);
			coef1=(coef>temp-coef)?temp-coef:coef;
			temp1=temp; temp-=coef; temp2=1;
			for(j=0; j<coef1; j++){
				temp2*=temp1;
				--temp1;
			}
			while(coef1>1){
				temp2/=coef1;
				--coef1;
			}
			result*=temp2;
		}
		printf("%lld\n", result);
	}
	return 0;
}
