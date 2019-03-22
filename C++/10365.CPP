#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a=0, b=0, c=0, n=0, m=0, i=0, j=0, limit=0, limit1=0, q=0, sur=0, min=0;
	scanf("%d",&q);
	while(q--){
		min=2147482637;
		scanf("%d",&n);
		limit=sqrt(n);
		for(i=1; i<=limit; i++){
			if(n%i==0){
				m=n/i;
				limit1=sqrt(m);
				for(j=1; j<=limit1; j++){
					if(m%j==0){
						a=i; b=j; c=m/j;
						sur=2*(a*b+b*c+a*c);
						if(sur<min) min=sur;
					}
				}
			}
		} 
		printf("%d\n", min);
	} 
	return 0;
}
