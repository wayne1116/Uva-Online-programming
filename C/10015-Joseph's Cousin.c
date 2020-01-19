#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prim[4096];
int main()
{
	int a=0, result=0, i=0, j=0, count=0, limit=0;
	prim[0]=2; count=1;
	for(i=3; i<35000; i+=2){
		limit=sqrt(i);
		for(j=2; j<=limit; j++){
			if(i%j==0) break;
		}
		if(j>limit) prim[count++]=i;
	}
	while(scanf("%d",&a)&&a){
		result=0;
		for(i=2; i<=a; i++) result=(result+prim[a-i])%i;
		printf("%d\n", result+1);
	}
	return 0;
}
