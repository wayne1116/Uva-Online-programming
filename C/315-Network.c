#include<stdio.h>
#include<stdlib.h>
int graph[128][128], n=0, flag[128];
void dfs(int prev, int next)             /*使用dfs往下搜尋,直到再次回到根節點(root)的時候*/ 
{
	int i=0;
	for(i=0; i<n; i++){
		if(flag[i]==0 && graph[next][i]){
			flag[i]=1;
			dfs(next,i);
			if(prev==next) break;
		}
	}
}
int main()
{
	int i=0, j=0, a=0, b=0, k=0, result=0;
	char line[1024], *ptr;
	while(scanf("%d",&n)&&n){
		getchar();
		for(i=0; i<n; i++){
			for(j=0; j<n; j++) graph[i][j]=0;
		}
		while(fgets(line,1024,stdin)!=NULL){
			if(line[0]=='0') break;
			ptr=line; a=atoi(ptr);
			while(*ptr){
				if(*ptr==' '){
					ptr++;
					b=atoi(ptr);
					graph[a-1][b-1]=graph[b-1][a-1]=1;
				}
				ptr++;
			}
		}
		result=0;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++) flag[j]=0;
			flag[i]=1; 
			dfs(i,i);
			for(j=0; j<n; j++){                /*假如dfs完後還有其他與根結點相連的點沒走到，代表說這個根結點是critical point*/ 
				if(flag[j]==0 && graph[i][j]){
					result++;
					break;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
