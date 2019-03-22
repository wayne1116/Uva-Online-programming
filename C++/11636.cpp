#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, j=0;
	int num[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
	
	while(scanf("%d",&a)!=EOF){
		if(a<0) break;
		for(j=0; j<15; j++) if(a<=num[j]) break;
		printf("Case %d: %d\n",++i, j);
	}
	return 0;	
} 
