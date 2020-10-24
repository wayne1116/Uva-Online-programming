#include<stdio.h>
#include<stdlib.h>
struct node{
	int x,y;
};
int main()
{
	int a=0, i=0, j=0, k=0, day=0, row=0, col=0, x, y;
	char line[128][128], line1[128][128], line2[128];
	struct node dir[4];
	dir[0].x=-1; dir[0].y=0;
	dir[1].x=1; dir[1].y=0;
	dir[2].x=0; dir[2].y=-1;
	dir[3].x=0; dir[3].y=1;
	
	scanf("%d",&a);
	while(a--){
		scanf("%d%d%d",&row,&col,&day); 
		for(i=0; i<row; i++) scanf("%s",line[i]);
		while(day--){
			for(i=0; i<row; i++){
				for(j=0; j<col; j++){
					line1[i][j]=line[i][j];
					for(k=0; k<4; k++){
						if(i+dir[k].x>=0 && j+dir[k].y>=0 && i+dir[k].x<row && j+dir[k].y<col){
							x=i+dir[k].x; y=j+dir[k].y;
							if(line[i][j]=='R' && line[x][y]=='P'){
								line1[i][j]='P';
								break;
							}
							else if(line[i][j]=='S' && line[x][y]=='R'){
								line1[i][j]='R';
								break;
							}
							else if(line[i][j]=='P' && line[x][y]=='S'){
								line1[i][j]='S';
								break;
							}
						}
					}
				}
			}
			for(i=0; i<row; i++){
				for(j=0; j<col; j++)line[i][j]=line1[i][j];
			}
		}
		for(i=0; i<row; i++){
			for(j=0; j<col; j++) printf("%c",line[i][j]);
			printf("\n");
		}
		if(a) printf("\n");
	}
	return 0;
}
