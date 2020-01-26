#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, number[64], temp=0, result=0, count=1;
	while(scanf("%d",&a) && a){
		for(i=0; i<a; i++) scanf("%d", &number[i]);
		temp=result=0;
		for(i=0; i<a; i++) temp+=number[i];
		temp/=a;
		for(i=0; i<a; i++){
			if(number[i]>temp) result+=number[i]-temp; 
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", count, result);
		count++;
	}
	return 0;
}
