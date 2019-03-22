#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[1024];
	int num[6], result=0, remaining=0, temp2=0, temp1=0;
	while(scanf("%d %d %d %d %d %d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5])){
		if(num[0]+num[1]+num[2]+num[3]+num[4]+num[5]==0) break;
		result=num[5]+num[4]+num[3]+num[2]/4;
		num[1]-=5*num[3];        /*負數沒關係,之後會補回來*/ 
		num[0]-=11*num[4];
	
		if(num[2]%4!=0){        /*當4x4的時候*/ 
			result++;
			remaining=num[2]%4;
			if(remaining==1){   /*當只有1個4x4的時候,需要5個2x2,7個1x1*/ 
				num[0]-=7;
				num[1]-=5;
			}
			else if(remaining==2){ /*當只有2個4x4的時候,需要3個2x2,6個1x1*/
				num[0]-=6;
				num[1]-=3;
			} 
			else if(remaining==3){ /*當只有3個4x4的時候,需要1個2x2,5個1x1*/
				num[0]-=5;
				num[1]-=1;
			}
		}
		
		if(num[1]>0){             
			result+=num[1]/9;
			if(num[1]%9!=0) result++;
			num[0]-=(36-4*(num[1]%9));
		}
		else if(num[1]<0) num[0]-=(-num[1]*4); /*彌補負數的時候,用1x1去補*/
		
		if(num[0]>0){
			result+=num[0]/36;
			if(num[0]%36!=0) result++;
		}
		printf("%d\n", result);
	}
	return 0;	
} 
