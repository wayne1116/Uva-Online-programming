#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, total=0, total1=0, flag=0, cycle=0, i=0, j=0, k=0;
	int number[2048], temp[2048];
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d/%d = ",a,b);
		if(a==0){
			printf("0.(0)\n");
			cycle=1;
		}
		else{
			if(a/b>0){
				while(a/b>0){
					printf("%d",a/b);
					a=a%b;
				}
				printf(".");
			}
			else printf("0.");
			temp[0]=a;
			a*=10; total=1; total1=0;
			while(a>0){
				number[total1++]=a/b;
				a=a%b; flag=0;
				for(i=0; i<total; i++){
					if(temp[i]==a){
						flag=1;
						break;
					}
				}
				if(flag){
					cycle=total-i;
					break;
				}
				else temp[total++]=a;
				a*=10;
			}
			if(a==0){
				cycle=1;
				for(j=0; j<total1; j++) printf("%d",number[j]);
				printf("(0)\n"); 
			}
			else{
				for(j=0; j<i; j++) printf("%d",number[j]);
				printf("(");
				if(cycle>50){
					for(j=i; j<i+50; j++) printf("%d",number[j]);
					printf("...)\n");
				}
				else{
					for(j=i; j<total1; j++) printf("%d",number[j]);
					printf(")\n");
				}
			}
		} 
		printf("   %d = number of digits in repeating cycle\n",cycle);
		printf("\n");
	}
	return 0;
}
