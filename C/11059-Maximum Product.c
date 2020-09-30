#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, j=0, count=1, k=0;
	long long number[32], init=0, max=0;
	while(scanf("%d",&a)!=EOF){
		for(i=0; i<a; i++) scanf("%lld",&number[i]);
		
		max=0;
		for(i=0; i<a; i++){
			for(j=i; j<a; j++){
				init=1;
				for(k=i; k<=j; k++)init*=number[k];
				if(max<init) max=init;
			}
			if(max<init) max=init;
		}
		if(max<=0) printf("Case #%d: The maximum product is 0.\n", count++);
		else printf("Case #%d: The maximum product is %lld.\n", count++, max);
		printf("\n");
	}
	return 0;
}
