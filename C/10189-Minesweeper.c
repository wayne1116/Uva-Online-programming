#include<stdio.h>
#include<stdlib.h>
struct node{
	int x,y;
};
int main()
{
	int a=0, b=0, i=0, j=0, k=0, tempx=0, tempy=0, count=0;
	char line[128][128];
	int result[128][128];
	struct node dir[8];
	dir[0].x=1; dir[0].y=0; dir[1].x=-1; dir[1].y=0;
	dir[2].x=0; dir[2].y=1; dir[3].x=0; dir[3].y=-1;
	dir[4].x=1; dir[4].y=1; dir[5].x=1; dir[5].y=-1;
	dir[6].x=-1; dir[6].y=-1; dir[7].x=-1; dir[7].y=1;
	
	while(scanf("%d%d",&a,&b)&&a&&b){
		if(count++>0) printf("\n");
		printf("Field #%d:\n", count);
		getchar();
		for(i=0; i<a; i++) fgets(line[i],128,stdin);
		for(i=0; i<a; i++){
			for(j=0; j<b; j++) result[i][j]=0;
		}
		for(i=0; i<a; i++){
			for(j=0; j<b; j++){
				if(line[i][j]=='*'){
					result[i][j]=-1;
					for(k=0; k<8; k++){
						tempx=i+dir[k].x; tempy=j+dir[k].y; 
						if(tempx>=0 && tempy>=0){
							if(line[tempx][tempy]=='.') ++result[tempx][tempy];
						}
					}
				}
			} 
		} 
		for(i=0; i<a; i++){
			for(j=0; j<b; j++){
				if(result[i][j]==-1) printf("%c",'*');
				else printf("%d",result[i][j]);
			} 
			printf("\n");
		} 
		
	}
	return 0;
}
