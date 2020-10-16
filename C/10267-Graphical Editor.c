#include<stdio.h>
#include<stdlib.h>
char image[256][256];
int flag[256][256];
int row, col;
int swap(int *a, int *b, int *c)
{
	*c=*a;
	*a=*b;
	*b=*c;
}
void func(int x, int y, char temp, char temp1)
{
	if(x<0||x>row||y<0||y>col||image[x][y]!=temp||flag[x][y])return;
	image[x][y]=temp1;
	flag[x][y]=1;
	func(x-1,y,temp,temp1);
	func(x+1,y,temp,temp1);
	func(x,y+1,temp,temp1);
	func(x,y-1,temp,temp1);
}
int main()
{
	char line[256], temp[256], temp1;
	int i, j, x1, x2, y1, y2, temp2;
	while(scanf("%s",line)!=EOF){
		if(line[0]=='X') break;
		else if(line[0]=='I'){
			scanf("%d %d",&col,&row);
			for(i=0; i<row; i++){
				for(j=0; j<col; j++) image[i][j]='O';
			} 
		} 
		else if(line[0]=='C'){
			for(i=0; i<row; i++){
				for(j=0; j<col; j++) image[i][j]='O';
			}
		}
		else if(line[0]=='S'){
			scanf("%s",temp);
			printf("%s\n", temp);
			for(i=0; i<row; i++){
				for(j=0; j<col; j++) printf("%c",image[i][j]);
				printf("\n");
			}
		}
		else if(line[0]=='F'){
			scanf("%d%d%s",&y1,&x1,temp);
			temp1=image[x1-1][y1-1];
			for(i=0; i<row; i++){
				for(j=0; j<col; j++) flag[i][j]=0;
			}
			func(x1-1,y1-1,temp1, temp[0]);
		}
		else if(line[0]=='L'){
			scanf("%d%d%s",&y1,&x1,temp);
			image[x1-1][y1-1]=temp[0];
		}
		else if(line[0]=='V'){
			scanf("%d%d%d%s",&x1,&y1,&y2,temp);
			if(y1>y2) swap(&y1,&y2,&temp2);
			for(i=y1-1; i<y2; i++) image[i][x1-1]=temp[0];
		}
		else if(line[0]=='H'){
			scanf("%d%d%d%s",&x1,&x2,&y1,temp);
			if(x1>x2) swap(&x1,&x2,&temp2);
			for(i=x1-1; i<x2; i++) image[y1-1][i]=temp[0];
		}
		else if(line[0]=='K'){
			scanf("%d%d%d%d%s",&x1,&y1,&x2,&y2,temp);
			if(x1>x2) swap(&x1,&x2,&temp2);
			if(y1>y2) swap(&y1,&y2,&temp2);
			for(i=x1-1; i<x2; i++){
				for(j=y1-1; j<y2; j++) image[j][i]=temp[0];
			}
		}
	}
	return 0;
}
