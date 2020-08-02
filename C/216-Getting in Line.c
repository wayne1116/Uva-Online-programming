#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 2147483647
int n=0, visited[16], number[16], result[16];
double min=0, distance[16][16];
void rec(int node, int start, int end, double dis)
{
	int i=0;
	visited[end]=1;
	number[node]=end;
	dis+=distance[start][end];
	if(node>=n){
		if(dis<min) {
			min=dis;
			for(i=1; i<=node; i++) result[i]=number[i];
		}
		return;
	}
	for(i=0; i<n; i++){
		if(visited[i]==0){
			rec(node+1,end,i, dis);
			visited[i]=0;
		}
	}
}
int main()
{
	int i=0, count=0, j=0, loc[16][2], k=1;
	double dis=0;
	while(scanf("%d",&n)&&n){
		for(i=0; i<n; i++) scanf("%d%d",&loc[i][0],&loc[i][1]);
		count=0;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i==j) distance[i][j]=0;
				else{
					dis=sqrt((loc[i][0]-loc[j][0])*(loc[i][0]-loc[j][0])+(loc[i][1]-loc[j][1])*(loc[i][1]-loc[j][1]));
					distance[i][j]=dis+16;
				}
			}
		}
		for(i=0; i<n; i++) visited[i]=0;
		min=MAX;
		for(i=0; i<n; i++){
			dis=0;
			rec(1,i,i,0);
			visited[i]=0;
		}
		printf("**********************************************************\n");
		printf("Network #%d\n",k++);
		for(i=1; i<n; i++) 
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", loc[result[i]][0], loc[result[i]][1], loc[result[i+1]][0], loc[result[i+1]][1], distance[result[i]][result[i+1]]);
		printf("Number of feet of cable required is %.2f.\n", min);	
	}
	return 0;
}
