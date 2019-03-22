#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, temp=0, result1=0, result2=0, count=0, i=0, j=0, k=0;
	float cal=0;
	while(scanf("%d",&a)!=EOF){
		if(k>0) printf("\n");
		temp=a-2; cal=((float)a-0.5)*((float)a-0.5);
		result1=0;
		for(i=a-1, j=1; j<a;){
			if(i*i+j*j<=cal){
				result1+=i;
				j++;
			}
			else i--;
		}
		result1*=4;
		result2=(temp+1+temp+2)*4;
		printf("In the case n = %d, %d cells contain segments of the circle.\n", a, result2);
		printf("There are %d cells completely contained in the circle.\n", result1);
		k++;
	}
	return 0;
}
