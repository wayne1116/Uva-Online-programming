#include<stdio.h>
#include<stdlib.h>
int main()
{
	double cow, car, open, result1, result2;
	while(scanf("%lf%lf%lf",&cow,&car,&open)!=EOF){
		result1=cow/(cow+car)*car/(cow+car-1-open);
		result2=car/(cow+car)*(car-1)/(cow+car-1-open);
		printf("%.5f\n", result1+result2);
	}
	return 0;
}
