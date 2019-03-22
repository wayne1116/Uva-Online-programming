#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, i, j, day, number, result;
	int flag[4096];
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&day,&number);
		for(i=0; i<day; i++) flag[i]=0;
		for(i=0; i<number; i++){
			scanf("%d",&b);
			flag[b-1]=1;
			for(j=b-1; j<day; j+=b) flag[j]=1;
		}
		result=0;
		for(i=0; i<day; i++){
			if(flag[i]&&i%7!=5&&i%7!=6) ++result;
		}
		printf("%d\n", result);
	}
	return 0;
}
