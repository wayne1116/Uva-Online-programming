#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, i=0, j=0, k=0;
	int max=0, sum=0, input=0, map[100][100];
	while(scanf("%d%d", &a, &b)!=EOF){
		if(a==0 && b==0)
			break;
		max=0;
		for(i=0; i<a; i++){
			for(j=0; j<b; j++){
				scanf("%d", &input);
				if(i>0){
					if(input==1) map[i][j]=0;
					else map[i][j]=map[i-1][j]+1;
				}
				else{
					if(input==1)
						map[0][j]=0;
					else
						map[0][j]=1;
				}
			}
			for(j=0; j<b; j++){
				sum=map[i][j];
				for(k=j-1; k>=0 && map[i][k]>=map[i][j]; k--)
					sum+=map[i][j];
				for(k=j+1; k<b && map[i][k]>=map[i][j]; k++)
					sum+=map[i][j];
				if(max<sum)
					max=sum;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
