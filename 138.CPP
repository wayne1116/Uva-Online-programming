#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long number1=6, number2=7, count=0, result=0;
	long long temp=0, temp1=0, temp2=0, temp3=0, temp4=0;
	while(count<10){
		temp1=(number1-1)*(number2-1);
		temp2=number1*number2;
		temp=temp1+temp2;
		temp4=temp*4+1;
		temp3=sqrt(temp4);
		if(temp4==temp3*temp3){
			result=(-1+temp3)/2;
			printf("%10d%10d\n", number1, result);
			count++;
		}
		number1++; number2++;
	}
	return 0;
}
