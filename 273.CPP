#include<stdio.h>
#include<stdlib.h>
struct node{
	int x1,x2,y1,y2;
};
int main()
{
	int a=0, n=0, i=0, u=0, v=0, u1=0, v1=0, j=0, k=0, l=0;
	int temp1_1, temp1_2, temp2_1, temp2_2, temp3_1, temp3_2, temp4_1, temp4_2;
	struct node lnode[16];
	int graph[16][16];
	scanf("%d",&a);
	while(a--){
		if(l>0) printf("\n");
		scanf("%d",&n);
		for(i=0; i<n; i++) scanf("%d%d%d%d",&lnode[i].x1,&lnode[i].y1,&lnode[i].x2,&lnode[i].y2);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(i!=j) graph[i][j]=0;
				else graph[i][j]=1;
			}
		}
		for(i=0; i<n; i++){
			u=(lnode[i].x2-lnode[i].x1); v=lnode[i].y2-lnode[i].y1;
			for(j=i+1; j<n; j++){
				u1=lnode[j].x2-lnode[j].x1; v1=lnode[j].y2-lnode[j].y1;
				temp1_1=lnode[j].x1-lnode[i].x1; temp1_2=lnode[j].y1-lnode[i].y1;
				temp2_1=lnode[j].x2-lnode[i].x1; temp2_2=lnode[j].y2-lnode[i].y1;
				temp3_1=lnode[i].x1-lnode[j].x1; temp3_2=lnode[i].y1-lnode[j].y1;
				temp4_1=lnode[i].x2-lnode[j].x1; temp4_2=lnode[i].y2-lnode[j].y1;
				if(lnode[i].x1<lnode[j].x1 && lnode[i].x2<lnode[j].x1 && lnode[i].x1<lnode[j].x2 && lnode[i].x2<lnode[j].x2);
				else if(lnode[i].y1<lnode[j].y1 && lnode[i].y2<lnode[j].y1 && lnode[i].y1<lnode[j].y2 && lnode[i].y2<lnode[j].y2);
				else if(lnode[i].x1>lnode[j].x1 && lnode[i].x2>lnode[j].x1 && lnode[i].x1>lnode[j].x2 && lnode[i].x2>lnode[j].x2);
				else if(lnode[i].y1>lnode[j].y1 && lnode[i].y2>lnode[j].y1 && lnode[i].y1>lnode[j].y2 && lnode[i].y2>lnode[j].y2);
				else if((u*temp1_2-v*temp1_1)*(u*temp2_2-v*temp2_1)<=0 && (u1*temp3_2-v1*temp3_1)*(u1*temp4_2-v1*temp4_1)<=0) graph[i][j]=graph[j][i]=1;
			}
		}
		for(k=0; k<n; k++){
			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					if(graph[i][k]&&graph[k][j]) graph[i][j]=1;
				}
			}
		}
		while(scanf("%d%d",&u,&v)){
			if(u==0 && v==0) break;
			if(graph[u-1][v-1]) printf("CONNECTED\n");
			else printf("NOT CONNECTED\n");
		}
		l++;
	}
	return 0;
} 
