#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0, j=0, a=0;
	long long result[30005]={1};
	int money[]={1,5,10,25,50};
	for(i=0; i<5; i++){
		for(j=money[i]; j<=30000; j++)
			result[j]+=result[j-money[i]];
	}
	while(scanf("%d",&a)!=EOF){
		if(result[a]==1) printf("There is only 1 way to produce %d cents change.\n", a);
		else printf("There are %lld ways to produce %d cents change.\n",result[a],a);
	}
	return 0;
}
