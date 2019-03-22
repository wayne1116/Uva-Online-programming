#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int result[100000];
int main()
{
	int a, b, target, i, j, limit;
	float count, diff, modify=1e-5;  //¤p¼ÆÂI»~®t 
	for(i=0; i<=10000; i++){
		target=i*i+i+41; 
		limit=sqrt(target);
		for(j=2; j<=limit; j++){
			if(target%j==0) break;
		}
		result[i]=0;
		if(j>limit) result[i]=1;
	}
		
	while(scanf("%d%d",&a,&b)!=EOF){
		count=0;
		for(i=a; i<=b; i++) count+=result[i];
		diff=b-a+1;
		count*=100;
		printf("%.2f\n", count/diff+modify);
	}
	return 0;
}
