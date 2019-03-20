#include<stdio.h>
#include<stdlib.h>
int main()
{
	int b1[3], b2[3], b3[3];
	int temp[6];
	int i=0, index=0, min=0;
	while(scanf("%d", &b1[0])!=EOF){
		for(i=1; i<3; i++) scanf("%d",&b1[i]);
		for(i=0; i<3; i++) scanf("%d",&b2[i]);
		for(i=0; i<3; i++) scanf("%d",&b3[i]);
		temp[0]=b1[1]+b1[2]+b2[0]+b2[1]+b3[0]+b3[2];
		temp[1]=b1[1]+b1[2]+b2[0]+b2[2]+b3[0]+b3[1];
		temp[2]=b1[0]+b1[1]+b2[1]+b2[2]+b3[0]+b3[2];
		temp[3]=b1[0]+b1[1]+b2[0]+b2[2]+b3[1]+b3[2];
		temp[4]=b1[0]+b1[2]+b2[1]+b2[2]+b3[0]+b3[1];
		temp[5]=b1[0]+b1[2]+b2[0]+b2[1]+b3[1]+b3[2];
		min=2147483647;
		for(i=0; i<6; i++){
			if(min>temp[i]){
				min=temp[i];
				index=i;
			}
		} 
		if(index==0) printf("BCG ");
		else if(index==1) printf("BGC ");
		else if(index==2) printf("CBG ");
		else if(index==3) printf("CGB ");
		else if(index==4) printf("GBC ");
		else printf("GCB ");
		printf("%d\n", min);
	}
	return 0;	
} 
