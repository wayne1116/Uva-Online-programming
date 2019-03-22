#include<stdio.h>
#include<stdlib.h>
struct node{
	int x,y;
};
int main()
{
	int a=0, i=0, row=0, col=0, x=0, y=0, d=0, flag=0;
	struct node dir[4];
	char line[128][128], line1[128], *ptr;
	dir[0].x=-1; dir[0].y=0;
	dir[1].x=0; dir[1].y=1;
	dir[2].x=1; dir[2].y=0;
	dir[3].x=0; dir[3].y=-1;
	
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&row,&col);
		getchar();
		for(i=0; i<row; i++) fgets(line[i],128,stdin);
		scanf("%d%d",&x,&y);
		getchar(); flag=0; d=0; x-=1; y-=1;
		while(fgets(line1,128,stdin)!=NULL){
			ptr=line1;
			while(*ptr){
				if(*ptr=='Q'){
					flag=1;
					break;
				}
				else if(*ptr=='R') d=(d+1)%4;
				else if(*ptr=='L') d=(d+3)%4;
				else if(*ptr=='F' && line[x+dir[d].x][y+dir[d].y]!='*'){
					x+=dir[d].x;
					y+=dir[d].y;
				}
				ptr++;
			}
			if(flag) break;
		}
		printf("%d %d %c\n", x+1, y+1, d==0?'N':(d==1?'E':(d==2?'S':'W')));
		if(a) printf("\n");
	}
	return 0;
}
