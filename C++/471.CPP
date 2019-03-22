#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, flag[16];
	long long num=0, result, result1, temp, i, j;
	scanf("%d",&a);
	while(a--){
		scanf("%lld", &num); j=1;
		temp=num;
		while(temp<=9876543210){
			result=temp;
			for(i=0; i<10; i++) flag[i]=0;
			while(result>0){
				if(flag[result%10]) break;
				flag[result%10]=1;
				result/=10;
			}
			result1=j;
			for(i=0; i<10; i++) flag[i]=0;
			while(result1>0){
				if(flag[result1%10]) break;
				flag[result1%10]=1;
				result1/=10;
			}
			if(result==0 && result1==0) printf("%lld / %lld = %lld\n", temp, j, num);
			temp+=num; ++j;
		}
		if(a) printf("\n");
	}
	return 0;
}
