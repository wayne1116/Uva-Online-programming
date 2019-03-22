#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int min1(int a, int b)
{
	return a>b?b:a;
}
int main()
{
	long long div=0, a=0, c1=0, c2=0, n1=0, n2=0;
	long long x=0, y=0, i=0, j=0, x1, x2, y1, y2;
	while(scanf("%lld",&a)&&a){
		scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
		div=gcd(n1,n2);
		if(a%div!=0 || a<min1(n1,n2)) printf("failed\n");  
		else{
			i=0; a/=div; n1/=div; n2/=div;
			while((a-i*n1)%n2!=0 && (a-i*n1)>=0) i++; //初始值 
			if(a-i*n1<0){
				printf("failed\n");
				continue;
			}
			x1=i; y1=(a-i*n1)/n2;                    //解為欲取最大值x以及最大值y 
			y2=y1-((y1/n1)*n1); x2=x1+((y1/n1)*n2);
			if(x1*c1+y1*c2<x2*c1+y2*c2){
				x=x1;
				y=y1;
			}
			else{
				x=x2;
				y=y2;
			}
			printf("%lld %lld\n", x, y);
		}
	}
	return 0;
} 
