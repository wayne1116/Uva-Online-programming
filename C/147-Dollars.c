#include<stdio.h>
#include<stdlib.h>
int main()
{
	int money[11]={1,2,4,10,20,40,100,200,400,1000,2000};
	double count[6001], number=0;
	int i=0, j=0, index=0;
	for(i=0; i<6001; i++) count[i]=1;
	for(i=1; i<11; i++){
		for(j=money[i]; j<=6000; j++){
			count[j]+=count[j-money[i]]; 
		}
	}
	while(scanf("%lf",&number)&&number){
		index=number*20;
		printf("%6.2f%17.0f\n",number,count[index]);
	}
	
	return 0;
}
