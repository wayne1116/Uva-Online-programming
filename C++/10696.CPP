#include<stdio.h>
#include<stdlib.h>
int solv(int num)
{
	if(num>=101) return num-10;
	return solv(solv(num+11)); 
} 
int main()
{
	int a=0;
	while(scanf("%d",&a)&&a){
		printf("f91(%d) = %d\n", a, solv(a));
	}
	return 0;
}
