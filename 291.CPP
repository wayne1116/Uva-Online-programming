#include<stdio.h>
#include<stdlib.h>
int graph[5][5], result[16];
void cal(int start, int step)
{
	int i=0;
	if(step>=8){
		for(i=0; i<step; i++) printf("%d",result[i]+1);
		printf("%d\n", start+1);
		return ;
	}
	for(i=0; i<5; i++){
		if(graph[start][i]){
			graph[start][i]=graph[i][start]=0;
			result[step]=start;
			cal(i,step+1);
			graph[start][i]=graph[i][start]=1;
		}
	}
}
int main()
{
	int i, j;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++) graph[i][j]=0;
	}
	graph[0][1]=graph[0][2]=graph[0][4]=1;
	graph[1][0]=graph[1][2]=graph[1][4]=1;
	graph[2][0]=graph[2][1]=graph[2][3]=graph[2][4]=1;
	graph[3][2]=graph[3][4]=1;
	graph[4][0]=graph[4][1]=graph[4][2]=graph[4][3]=1;
	cal(0,0);
	return 0;
}
