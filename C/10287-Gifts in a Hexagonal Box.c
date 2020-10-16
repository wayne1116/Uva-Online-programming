#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	const double temp=sqrt(3.0);
	double r1, r2 ,r3 ,r4;
	double a, b, c, len;
	while(scanf("%lf",&len)!=EOF){
		r1=temp*len/2;
		r2=len/(1.0+2.0/temp);
		r3=r1/2;
		a=5.0/3.0;
		b=7.0/temp*len;
		c=-7.0/4.0*len*len;
		r4=(-b+sqrt(b*b-4*a*c))/2/a;
		printf("%.10f %.10f %.10f %.10f\n", r1, r2, r3 ,r4);
		
	}
	return 0;
}
