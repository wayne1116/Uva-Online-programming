#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0, number1=0, number2=0, a=0;
	int count2=0, count4=0, count6=0, count8=0;
	int result=0, result2[1024], result4[1024], result6[1024], result8[1024];
	count2=0;
	for(i=0; i<100; i++){
		number1=i/10;
		number2=i%10;
		result=(number1+number2)*(number1+number2);
		if(result==i) result2[count2++]=i;
	}
	count4=0;
	for(i=0; i<10000; i++){
		number1=i/100;
		number2=i%100;
		result=(number1+number2)*(number1+number2);
		if(result==i) result4[count4++]=i; 
	}
	count6=0;
	for(i=0; i<1000000; i++){
		number1=i/1000;
		number2=i%1000;
		result=(number1+number2)*(number1+number2);
		if(result==i) result6[count6++]=i;
	}
	count8=0;
	for(i=0; i<100000000; i++){
		number1=i/10000;
		number2=i%10000;
		result=(number1+number2)*(number1+number2);
		if(result==i) result8[count8++]=i;
	}
	while(scanf("%d",&a)!=EOF){
		if(a==2) for(i=0; i<count2; i++) printf("%02d\n", result2[i]);
		else if(a==4) for(i=0; i<count4; i++) printf("%04d\n", result4[i]);
		else if(a==6) for(i=0; i<count6; i++) printf("%06d\n", result6[i]);
		else for(i=0; i<count8; i++) printf("%08d\n", result8[i]); 
	}
	return 0;
}
