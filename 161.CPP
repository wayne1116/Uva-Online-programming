#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[128], n=0, i=0, result=0, time[128], flag=0;
	while(scanf("%d",&num[0])&&num[0]){
		n=1;
		while(scanf("%d",&num[n])&&num[n]) n++;
		result=2147483647;
		for(i=0; i<n; i++){
			if(result>num[i]) result=num[i];
			time[i]=0;
		}
		while(result<=18000){
			flag=1;
			for(i=0; i<n; i++){                                      /*計算出的result與全部做比較*/ 
				while(time[i]+num[i]-5<=result) time[i]+=2*num[i];  /*找出該num[i]點大於result的最小2*num[i]倍數*/ 
				if(!(time[i]<=result && time[i]+num[i]-5>result)){
					result=time[i]-1;
					flag=0;
					break;
				}
			}
			if(flag) break;
			result++;
		}
		if(result>18000) printf("Signals fail to synchronise in 5 hours\n");
		else printf("%02d:%02d:%02d\n",result/3600,result%3600/60,result%60);
	}
	return 0;
}
