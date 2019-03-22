#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long a, n, x, y, value, diff;
	while(scanf("%lld",&a)&&a){
		n=(-1+sqrt(4*a-3))/2;
		x=y=n+1; value=1+(1+n)*n;
		diff=a-value;
		if(n%2==0){
			if(diff<=n) x-=diff;
			else{
				x=1; ++y;
				diff=diff-n-1;
				x+=diff;
			}
		}
		else{
			if(diff<=n) y-=diff;
			else{
				y=1; ++x;
				diff=diff-n-1;
				y+=diff;
			}
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
}
