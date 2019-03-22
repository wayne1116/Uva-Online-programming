#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int count=0, i=0, temp=0, state=0, j=0;
	int a=0, cou[128], number[128];
	for(i=2; i<100; i++){
		temp=sqrt(i); state=1;
		for(j=2; j<=temp; j++){
			if(i%j==0){
				state=0;
				break;
			}
		}
		if(state) number[count++]=i;
	}
	while(scanf("%d",&a)&&a){
		for(i=0; i<count; i++) cou[i]=0;
		for(i=2; i<=a; i++){
			temp=i;
			for(j=0; j<count; j++){
				while(temp%number[j]==0){
					cou[j]++;
					temp/=number[j];
				}
			}
		}
		printf("%3d! =", a);
		for(i=0; i<count; i++){
			if(cou[i]==0) break;
			if(i%14==1 && i!=1) printf("      ");
			printf("%3d", cou[i]);
			if(i%14==0 && i!=0) printf("\n");
		}
		if(i%14!=1 || i==1) printf("\n"); 
	}
	return 0;
}
