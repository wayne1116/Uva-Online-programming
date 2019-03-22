#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, result=0, carry=0, result1=0;
	while(scanf("%d%d",&a,&b)&&(a||b)){
		carry=0; result1=0; 
		while(a||b){
			result=a%10+b%10+carry;
			if(result>9){
				carry=1;
				result1++;
			}
			else carry=0;
			a/=10; b/=10;
		}
		if(result1>1) printf("%d carry operations.\n", result1);
		else if(result1==1) printf("1 carry operation.\n");
		else printf("No carry operation.\n");
		
	}
	return 0;
}
