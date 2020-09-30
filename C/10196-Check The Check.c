#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[16][16];
	int i, j, bkingx, bkingy,wkingx, wkingy, flag1, flag2, index=0;
	int dirx[4], diry[4], plusx[4], plusy[4];
	while(1){
		bkingx=wkingx=bkingy=wkingy=-1;
		for(i=2; i<=9; i++){
			scanf("%s",line[i]);
			for(j=9; j>1; j--) line[i][j]=line[i][j-2];
			line[i][0]=line[i][1]='\0';
			for(j=2; j<=9; j++){
				if(line[i][j]=='k'){
					bkingx=i;
					bkingy=j;
				}
				else if(line[i][j]=='K'){
					wkingx=i;
					wkingy=j;
				}
			}
		}
		if(bkingx==-1||wkingx==-1||bkingy==-1||wkingy==-1) break;
		flag1=flag2=0;
		if(line[bkingx+1][bkingy-1]=='P'||line[bkingx+1][bkingy+1]=='P') flag1=1;
		else if(line[wkingx-1][wkingy-1]=='p'||line[wkingx-1][wkingy+1]=='p') flag2=1;
		else if(line[bkingx-1][bkingy+2]=='N'||line[bkingx-1][bkingy-2]=='N'||line[bkingx-2][bkingy+1]=='N'||line[bkingx-2][bkingy-1]=='N') flag1=1;
		else if(line[bkingx+1][bkingy-2]=='N'||line[bkingx+1][bkingy+2]=='N'||line[bkingx+2][bkingy-1]=='N'||line[bkingx+2][bkingy+1]=='N') flag1=1;
		else if(line[wkingx-1][wkingy+2]=='n'||line[wkingx-1][wkingy-2]=='n'||line[wkingx-2][wkingy+1]=='n'||line[wkingx-2][wkingy-1]=='n') flag2=1;
		else if(line[wkingx+1][wkingy-2]=='n'||line[wkingx+1][wkingy+2]=='n'||line[wkingx+2][wkingy-1]=='n'||line[wkingx+2][wkingy+1]=='n') flag2=1;
		dirx[0]=bkingx-1; diry[0]=bkingy;
		dirx[1]=bkingx+1; diry[1]=bkingy;
		dirx[2]=bkingx; diry[2]=bkingy+1;
		dirx[3]=bkingx; diry[3]=bkingy-1;
		plusx[0]=-1; plusy[0]=0;
		plusx[1]=1; plusy[1]=0;
		plusx[2]=0; plusy[2]=1;
		plusx[3]=0; plusy[3]=-1;
		for(i=0; i<4; i++){
			while(line[dirx[i]][diry[i]]=='.'){
				dirx[i]+=plusx[i];
				diry[i]+=plusy[i];
			}
			if(line[dirx[i]][diry[i]]=='R'||line[dirx[i]][diry[i]]=='Q') flag1=1;
		}
		dirx[0]=wkingx-1; diry[0]=wkingy;
		dirx[1]=wkingx+1; diry[1]=wkingy;
		dirx[2]=wkingx; diry[2]=wkingy+1;
		dirx[3]=wkingx; diry[3]=wkingy-1;
		plusx[0]=-1; plusy[0]=0;
		plusx[1]=1; plusy[1]=0;
		plusx[2]=0; plusy[2]=1;
		plusx[3]=0; plusy[3]=-1;
		for(i=0; i<4; i++){
			while(line[dirx[i]][diry[i]]=='.'){
				dirx[i]+=plusx[i];
				diry[i]+=plusy[i];
			}
			if(line[dirx[i]][diry[i]]=='r'||line[dirx[i]][diry[i]]=='q') flag2=1;
		}
		dirx[0]=bkingx-1; diry[0]=bkingy-1;
		dirx[1]=bkingx-1; diry[1]=bkingy+1;
		dirx[2]=bkingx+1; diry[2]=bkingy+1;
		dirx[3]=bkingx+1; diry[3]=bkingy-1;
		plusx[0]=-1; plusy[0]=-1;
		plusx[1]=-1; plusy[1]=+1;
		plusx[2]=1; plusy[2]=1;
		plusx[3]=1; plusy[3]=-1;
		for(i=0; i<4; i++){
			while(line[dirx[i]][diry[i]]=='.'){
				dirx[i]+=plusx[i];
				diry[i]+=plusy[i];
			}
			if(line[dirx[i]][diry[i]]=='B'||line[dirx[i]][diry[i]]=='Q') flag1=1;
		}
		dirx[0]=wkingx-1; diry[0]=wkingy-1;
		dirx[1]=wkingx-1; diry[1]=wkingy+1;
		dirx[2]=wkingx+1; diry[2]=wkingy+1;
		dirx[3]=wkingx+1; diry[3]=wkingy-1;
		plusx[0]=-1; plusy[0]=-1;
		plusx[1]=-1; plusy[1]=+1;
		plusx[2]=1; plusy[2]=1;
		plusx[3]=1; plusy[3]=-1;
		for(i=0; i<4; i++){
			while(line[dirx[i]][diry[i]]=='.'){
				dirx[i]+=plusx[i];
				diry[i]+=plusy[i];
			}
			if(line[dirx[i]][diry[i]]=='b'||line[dirx[i]][diry[i]]=='q') flag2=1;
		}
		printf("Game #%d: ", ++index);
		if(flag1) printf("black king is in check.\n");
		else if(flag2) printf("white king is in check.\n");
		else printf("no king is in check.\n");
	}
	return 0;
}
