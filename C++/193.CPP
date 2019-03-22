#include<stdio.h>
#include<stdlib.h>
int max=0, count=0, n=0;
int color[128], result[128], graph[128][128];
void cal(int node, int black)
{
	int i=0;
	if(node>n){
		if(max<black){
			max=black;
			count=0;
			for(i=1; i<=n; i++){
				if(color[i]) result[count++]=i;
			}
		}
		return;
	}
	for(i=1; i<=n; i++){
		if(graph[node][i] && color[i]){
			cal(node+1,black);
			return;
		}
	}
	color[node]=1;
	cal(node+1,black+1);
	color[node]=0;
	cal(node+1, black);
}
int main()
{
	int a=0, edge=0, i=0, u=0, v=0, j=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&n,&edge);
		for(i=0; i<=n; i++){
			for(j=0; j<=n; j++) graph[i][j]=0;
			color[i]=0;
		}
		for(i=0; i<edge; i++){
			scanf("%d%d",&u,&v);
			graph[u][v]=graph[v][u]=1;
		}
		max=0;
		cal(1, 0);
		printf("%d\n", max);
		for(i=0; i<max-1; i++) printf("%d ", result[i]);
		printf("%d\n", result[i]); 
	}
	return 0;
} 
