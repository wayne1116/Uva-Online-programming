#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int temp[2048];
	int number1=0, number2=0, number3=0;
	int count1=0, count2=0, count3=0;
	temp[0]=1;
	for(i=1; i<1500; i++){
		number1=temp[count1]*2;
		number2=temp[count2]*3;
		number3=temp[count3]*5;
		if(number1<number2){
			if(number1<number3){
				temp[i]=number1;
				count1++;
			}
			else{
				temp[i]=number3;
				count3++;
			}
		}
		else{
			if(number2<number3) {
				temp[i]=number2;
				count2++;
			}
			else {
				temp[i]=number3;
				count3++;
			}
		}
	}
	for(i=0; i<1500; i++){
		printf("%d ", temp[i]);
		if(i%10==0 && i>0) printf("\n");
	}
	return 0;
}
