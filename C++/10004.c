#include<stdio.h>
#include<stdlib.h>
int dfs(int map[200][200], int color[200], int n, int start)
{
	int i=0;
	for(i=0; i<n; i++){
		if(map[start][i]){
			if(color[start]==color[i])
				return 0;
			else if(color[i]==0){
				color[i]=-color[start];
				if(!dfs(map,color,n,i))
					return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int a=0, b=0, i=0, j=0, state=0, x=0, y=0;
	int map[200][200], color[200];
	while(scanf("%d", &a)!=EOF){
		if(a==0)
			break;
		scanf("%d", &b);
		for(i=0; i<a; i++){
			color[i]=0;
		}
		for(i=0; i<a; i++)
			for(j=0; j<a; j++)
				map[i][j]=0;
			for(i=0; i<b; i++){
				scanf("%d %d", &x, &y);
				map[x][y]=map[y][x]=1;
			}

		state=1;
		for(i=0; i<a; i++){
			if(!color[i]){
				color[i]=1;
				if(!dfs(map,color,a,i)){
					state=0;
					break;
				}
			}
		}
		if(!state)
			printf("NOT ");
		printf("BICOLORABLE.\n");
	}
	return 0;
}
