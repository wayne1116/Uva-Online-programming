#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, j=0, count=0, pos=0, state=0;
	int dead[128];
	while(scanf("%d", &a)&&a){
		for(i=1; i<=a; i++){
			for(j=0; j<a; j++) dead[j]=0;
			
			dead[0]=1;
			count=a-1; pos=0; state=1;
			while(count>1){
				for(j=0; j<i; j++){
					do{
						pos++;
						if(pos>=a) pos=0;
						 
					}while(dead[pos]);
				}
				if(pos==12){
					state=0;
					break;
				}
				dead[pos]=1;
				count--;
			}
			if(state){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
