#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0, k=0, m=0;
	int cur1=0, cur2=0, count=0, i=0, j=0;
	int flag[32];
	while(scanf("%d%d%d",&n,&k,&m)&&n&&k&&m){
		for(i=0; i<n; i++) flag[i]=0;
		cur1=0; cur2=n-1;
		count=n; j=0;
		while(count>0){
			if(j>0) printf(",");
			while(flag[cur1]) cur1=(cur1+1)%n;
			while(flag[cur2]) cur2=(cur2+n-1)%n;
			i=1;
			while(i<k){
				cur1=(cur1+1)%n;
				if(!flag[cur1]){
					i++;
				}
			}
			i=1;
			while(i<m){
				cur2=(cur2+n-1)%n;
				if(!flag[cur2])i++;
			}
			if(cur1!=cur2){
				printf("%3d%3d",cur1+1,cur2+1);
				count-=2;
			}
			else {
				printf("%3d",cur1+1);
				count--;
			}
			flag[cur1]=flag[cur2]=1;
			j++;
		} 
		printf("\n");
	}
	return 0;
}
