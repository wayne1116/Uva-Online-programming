#include<stdio.h>
#include<stdlib.h>
int parent[1024];
int cal(int a)
{
	while(parent[a]>=0) a=parent[a];
	return a;
}
int main()
{
	int a=0, n=0, i=0, u=0, v=0, count=0;
	char line[16];
	scanf("%d",&a);
	while(a--){
		scanf("%s",line); getchar();
		n=line[0]-64;
		for(i=0; i<n; i++) parent[i]=-1;
		while(fgets(line,16,stdin)!=NULL){
			if(line[0]<'A' || line[0]>'Z') break;
			u=cal(line[0]-65);
			v=cal(line[1]-65);
			if(u!=v){
				if(parent[u]>parent[v]){
					parent[v]+=parent[u];
					parent[u]=v;
				}
				else{
					parent[u]+=parent[v];
					parent[v]=u;
				}
			}
		}
		count=0; 
		for(i=0; i<n; i++){
			if(parent[i]<0) ++count;
		} 
		printf("%d\n", count);
		if(a) printf("\n");
	}
	return 0;
}
