#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, i=0, result=0, number[1024], average=0, person=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d",&b);
		result=0;
		for(i=0; i<b; i++){
			scanf("%d",&number[i]);
			result+=number[i];
		}
		average=result/b;
		person=0;
		for(i=0; i<b; i++){
			if(number[i]>average) person++;
		}
		printf("%.3f%%\n", 100.0*(float)person/(float)b);
	}
	return 0;	
} 
