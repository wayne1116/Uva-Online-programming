#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node{
	char line[32][32];
};
struct node1{
	int x,y,z;
};
int main()
{
	int h, row, col, i, j, k, flag, count, size;
	int sth, str, stc, temph, tempr, tempc, edh, edr, edc;
	struct node lnode[32];
	struct node1 temp, dir[6];
	queue<pair<int,struct node1> > qu;
	pair<int,struct node1> iter;
	
	dir[0].x=0; dir[0].y=0; dir[0].z=1;
	dir[1].x=0; dir[1].y=0; dir[1].z=-1;
	dir[2].x=1; dir[2].y=0; dir[2].z=0;
	dir[3].x=-1; dir[3].y=0; dir[3].z=0;
	dir[4].x=0; dir[4].y=1; dir[4].z=0;
	dir[5].x=0; dir[5].y=-1; dir[5].z=0;
	
	while(scanf("%d%d%d",&h,&row,&col)!=EOF){
		if(h+row+col==0) break;
		getchar();
		for(i=0; i<h; i++){
			for(j=0; j<row; j++){
				for(k=0; k<col; k++){
					lnode[i].line[j][k]=getchar();
					if(lnode[i].line[j][k]=='S'){
						sth=i;
						str=j;
						stc=k;
					}
					else if(lnode[i].line[j][k]=='E'){
						edh=i;
						edr=j;
						edc=k;
					}
				}
				lnode[i].line[j][k]='\0';
				getchar();
			}
			getchar();
		}
		lnode[sth].line[str][stc]='#';
		temp.x=str; temp.y=stc; flag=0; count=0;
		qu.push(pair<int,struct node1>(sth,temp));
		while(qu.size()>0){
			size=qu.size();
			for(i=0; i<size; i++){
				iter=qu.front(); qu.pop();
				temph=iter.first; tempr=(iter.second).x; tempc=(iter.second).y;
				if(temph==edh && tempr==edr && tempc==edc){
					flag=1;
					break;
				} 
				for(j=0; j<6; j++){
					if(temph+dir[j].z>=0 && temph+dir[j].z<h && tempr+dir[j].x>=0 && tempr+dir[j].x<row && tempc+dir[j].y>=0 && tempc+dir[j].y<col){
						if(lnode[temph+dir[j].z].line[tempr+dir[j].x][tempc+dir[j].y]!='#'){
							temp.x=tempr+dir[j].x;
							temp.y=tempc+dir[j].y;
							qu.push(pair<int,struct node1>(temph+dir[j].z,temp));
							lnode[temph+dir[j].z].line[temp.x][temp.y]='#';           //選到queue裡面就要將那個位置標上'#',避免TLE 
						}
					}
				}
			}
			if(flag) break;
			++count;
		}
		if(flag) printf("Escaped in %d minute(s).\n", count);
		else printf("Trapped!\n");
		while(!qu.empty()) qu.pop();
	}
	return 0;
}
