#include<stdio.h>
#include<stdlib.h>
#define abs(a,b) ((a)>(b)?(a-b):(b-a))
int result[92][8], column[8];
int count=0;
void qu(int step)
{
	int i=0, j=0, flag=0;
	if(step<8){
		for(i=0; i<8; i++){
			flag=1;
			for(j=0; j<step; j++){
				if(i==column[j] || abs(step,j)==abs(i,column[j])){  /*column[j]==i or column[j]-i==j-step or column[j]-i==step-j*/
					flag=0;                                         /*j是代表第j行, column[j]是紀錄第x列, 假如abs相同代表在同一斜列*/ 
					break;
				}
			}
			if(flag){
				column[step]=i;
				qu(step+1);
			}
		}
	}
	else{
		for(i=0; i<8; i++) result[count][i]=column[i];
		count++;
	}
}
int main()
{
	int i=0, j=0, queue[8][8], max=0, sum=0, n=0;
	for(i=0; i<8; i++){
		column[0]=i;
		qu(1);
	}
	scanf("%d",&n);
	while(n--){
		for(i=0; i<8; i++)
			for(j=0; j<8; j++) scanf("%d",&queue[i][j]);
		
		max=0;
		for(i=0; i<count; i++){
			sum=0;
			for(j=0; j<8; j++) sum+=queue[j][result[i][j]];
			if(max<sum) max=sum;
		} 
		printf("%5d\n",max);
	}
	return 0;
}
