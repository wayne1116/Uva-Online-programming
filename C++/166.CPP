#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a)>(b)?(b):(a))
int main()
{
	int num[6], result=0, money=0, a=0, b=0, i=0, j=0, k=0, sum=0;
	int change1[41]={0}, mon[6]={1,2,4,10,20,40},change2[1000];
	
	for(i=0; i<=40; i++) change1[i]=i;
	for(i=1; i<6; i++){
		for(j=mon[i]; j<=40; j++) change1[j]=min(change1[j],change1[j-mon[i]]+1);    /*店家找零錢給客人的最少零錢數，最大不會超過$2 */ 
	}
	
	while(scanf("%d",&num[0])!=EOF){
		sum=num[0]*mon[0];
		for(i=1; i<6; i++){
			scanf("%d",&num[i]);
			sum+=num[i]*mon[i];
		}
		if(!sum) break;
		scanf("%d.%d",&a,&b);
		money=(a*100+b)/5; 
		
		
		for(i=1; i<1000; i++) change2[i]=9999;
		change2[0]=0;
		for(i=0; i<6; i++){                      /*客人手上擁有可能的零錢*/ 
			for(j=sum; j>=mon[i]; j--){
				for(k=1; k<=num[i]; k++){
					if(j-mon[i]*k<0) break;
					change2[j]=min(change2[j],change2[j-mon[i]*k]+k);
				}
			}
		}
		result=9999;
		for(i=0; i<40; i++)result=min(result,change1[i]+change2[money+i]);
		printf("%3d\n", result);
	}
	return 0;
}
