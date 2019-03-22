#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0, m=0, i=0, j=0, k=0, l=0, u=0, o=0, temp=0, index=1, flag=0;
	int count[32], h[32][32], v[32][32];
	char com[32];
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		if(index>1) printf("\n**********************************\n\n");
		for(i=0; i<32; i++){
			for(j=0; j<32; j++) h[i][j]=v[i][j]=0;
			count[i]=0;
		}
		for(i=0; i<m; i++){
			scanf("%s%d%d",com,&u,&o);
			if(com[0]=='H') h[u][o]=1;
			else v[u][o]=1;
		}
		for(i=1; i<n; i++){
			for(j=1; j<n; j++){
				for(k=1; k<n; k++){
					temp=0;
					for(l=0; l<k; l++) temp+=h[i][j+l]+h[i+k][j+l]+v[j][i+l]+v[j+k][i+l];
					if(temp==4*k) count[k]++;
				}
			}
		}
		printf("Problem #%d\n\n", index);
		flag=1;
		for(i=1; i<n; i++){
			if(count[i]>0){
				flag=0;
				printf("%d square (s) of size %d\n", count[i], i);
			}
		}
		if(flag) printf("No completed squares can be found.\n");
		index++;
	}
	return 0;
}
