#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double a=0, sq=0, cir=0, temp=0;
	double number1=0, number2=0, number3=0;
	while(scanf("%lf",&a)!=EOF){
		sq=a*a;
		cir=a*a*2*acos(0.0);
		temp=sqrt(3)/2.0;
		number3=sq-a*a*temp/2.0-cir/6.0;
		number2=sq-cir/4.0-2.0*number3;
		number2*=4.0;
		number3*=4.0;
		number1=sq-number2-number3;
		printf("%.3f %.3f %.3f\n", number1, number2, number3);
	}
	return 0;
}
