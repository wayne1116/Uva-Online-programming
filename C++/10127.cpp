#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, remain, result;
	while(scanf("%d",&a)!=EOF){
		result=0;
		remain=1;
		while(1){
			remain=remain%a;
			if(remain==0){
				printf("%d\n", result+1);
				break;
			}
			else remain=remain*10+1;
			result++;
		}
	}
	return 0;
} 
