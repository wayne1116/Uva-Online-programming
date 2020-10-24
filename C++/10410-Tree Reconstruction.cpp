#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
int vect[1024][1024];
int main()
{
	int n=0, i=0, j=0, a, u=0;
	int parent[1024], dfsn[1024], pos[1024], count[1024];
	stack<int> sta;
	while(scanf("%d",&n)!=EOF){
		for(i=0; i<n; i++){
			scanf("%d",&a);
			pos[a]=i;
			parent[a]=-1;
			count[i+1]=0;
		}
		for(i=0; i<n; i++) scanf("%d",&dfsn[i]);
		while(!sta.empty()) sta.pop();
		sta.push(dfsn[0]);
		for(i=1; i<n; i++){
			while(1){
				u=sta.top();
				if(u==dfsn[0]||pos[u]+1<pos[dfsn[i]]){ //¦V¤W·j´M¨Ó·½ 
					parent[dfsn[i]]=u;
					sta.push(dfsn[i]);
					break;
				}
				else sta.pop();
			}
		}
		for(i=1; i<=n; i++){
			if(parent[i]!=-1){
				vect[parent[i]][count[parent[i]]]=i;
				count[parent[i]]++;
			}
		}
		for(i=1; i<=n; i++){
			printf("%d:", i);
			for(j=0; j<count[i]; j++) printf(" %d", vect[i][j]);
			printf("\n");
		}
	}
	return 0;
}
