#include<stdio.h>
#include<stdlib.h>
int abs(int a)
{
	return a>0?a:-a;
}
int cmp(const void *x, const void *y)
{
	return *(int*)y-*(int*)x;
}
int main()
{
	int a, i, ans, mon[1024], integer, remain, sum, temp, temp1;
	while(scanf("%d",&a)){
		if(a==0) break;
		sum=0;
		for(i=0; i<a; i++){
			scanf("%d.%d",&temp,&temp1);
			mon[i]=temp*100+temp1;
			sum+=mon[i];
		}
		qsort(mon,a,sizeof(int),cmp);
		integer=sum/a;
		remain=sum%a;
		ans=0;
		for(i=0; i<a; i++){
			if(remain>0){
				remain--;
				ans+=abs(mon[i]-(integer+1));
			}
			else ans+=abs(mon[i]-integer);
		}
		printf("$%.2lf\n",(double)ans/200);
	}
	return 0;
}
