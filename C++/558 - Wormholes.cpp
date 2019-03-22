#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define INTMAX 2147483647
using namespace std;
vector<pair<int,int> > con[5001];
int SPFA(int s, int n)
{
	int i=0, j=0;
	queue<int> q;
	bool flag[5001];
	int d[5001];
	int x=0, size=0;
	pair<int,int> temp;
	for(i=0; i<n; i++) {
		d[i]=INTMAX;
		flag[i]=false;
	}
	d[s]=0;
	q.push(s); flag[s]=true;
	while(q.size()){
		x=q.front(); q.pop();
		size=con[x].size();
		for(i=0; i<size; i++){
			temp=con[x][i];
			if(d[temp.first]>d[x]+temp.second){
				d[temp.first]=d[x]+temp.second;
				if(!flag[temp.first]){
					flag[temp.first]=true;
					q.push(temp.first);
				}
			}
		} 
	}
	for(int i=0; i<n; i++){
		size=con[i].size();
		for(j=0; j<size; j++){
			temp=con[i][j];
			if(d[temp.first]>d[i]+temp.second) return -1;
		}
	}
	//if(d[e]==INTMAX) return -1;
	return 1;
} 
int main()
{
	int a=0, n=0, m=0, q=0, i=0, j=0;
	int s=0, e=0, w=0;
	int result=0;
	scanf("%d", &a);
	for(i=0; i<a; i++){
		scanf("%d%d", &n,&m);
		for(j=0; j<n; j++)
			con[j].clear();
		for(j=0; j<m; j++){
			scanf("%d%d%d",&s,&e,&w);
			con[s].push_back(pair<int,int>(e,w));
		}
		result=SPFA(0,n);
		if(result==-1) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}
