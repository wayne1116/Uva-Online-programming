#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define abs(a) ((a)>0?(a):(-a))
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))

int main()
{
	char line[1024], *ptr;
	long long num1, num2, i, count=0, temp, y, x;
	while(fgets(line,128,stdin)!=NULL){
		if(sscanf(line,"%lld%lld",&num1,&num2)==2){
			count=0; if(abs(num1)%2==1) num1++;
			for(i=num1; i<=num2; i+=2){
				if(abs(i)%4) ++count;
			}
			printf("%lld\n", count);
		}
		else{
			sscanf(line,"%lld%lld",&num1);
			if(abs(num1)%2==1||abs(num1)%4==0){
				temp=num1;
				num1=abs(num1);
				if(num1%2==1){
					x=(num1+1)/2; 
					y=(num1-1)/2;
				}
				else{
					x=num1/4+1;
					y=num1/4-1;
				} 
				if(temp<0) swap(x,y,temp);
				printf("%lld %lld\n", x, y);
			} 
			else printf("Bachelor Number.\n");
		}
	}
	return 0;
}
