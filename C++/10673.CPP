#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, j=0, b=0, c=0, number1=0, number2=0, temp=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&b,&c);
		number1=b/c;
		if(b%c==0) number2=number1;
		else number2=number1+1;
		
		for(i=0; i<=b; i++){
			for(j=0; j<=b; j++){
				temp=i*number1+j*number2;
				if(temp>=b) break; 
			}
			if(temp==b) break;
		}
		printf("%d %d\n", i, j);
	}
	return 0;	
} 
