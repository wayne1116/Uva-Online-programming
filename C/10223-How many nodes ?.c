#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long result[32]={1}, a;
	int i;
	for(i=1; i<20; i++){
		result[i]=result[i-1]*2*(2*i+1)/(i+2);
	}
	while(scanf("%lld",&a)!=EOF){
		for(i=0; i<20; i++) if(result[i]==a) break;
		printf("%d\n", i+1);
	}
	return 0;
}
