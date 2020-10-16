#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double sum=0;
	int a, b, i;
	while(scanf("%d%d",&a,&b)!=EOF){ 
		sum=0; 
		if(a-b>b){
			for(i=1; i<=b; i++)	sum+=log10(a-i+1)-log10(i);
			printf("%d\n", (int)sum+1);
		}
		else{
			for(i=1; i<=a-b; i++) sum+=log10(a-i+1)-log10(i);
			printf("%d\n", (int)sum+1); 
		}
	}
	return 0;
} 
