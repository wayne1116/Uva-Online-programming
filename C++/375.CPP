#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double edge=0, radius=0, temph=0, B=0, H=0, result=0;
	double const pi=2*asin(1);
	int a=0;
	scanf("%d",&a);
	while(a--){
		scanf("%lf%lf",&B,&H);
		result=0;
		while(1){
			edge=sqrt(B*B/2.0/2.0+H*H);
			radius=B*H/(2*edge+B);
			if(radius<0.000001) break;
			result=result+radius*pi*2.0;
			temph=H-2*radius;
			B=B*(temph/H);
			H=temph;
		}
		printf("%13.6f\n", result);
		if(a) printf("\n");
	}
	return 0;
}
