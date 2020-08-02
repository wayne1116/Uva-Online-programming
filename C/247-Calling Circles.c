#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n=0, m=0, i=0, j=0, k=0, total=0, con[32][32], group[32], index=0, count=1;
	char name[32][32], name1[32], name2[32];
	while(scanf("%d%d",&n,&m)&&n&&m){
		printf("Calling circles for data set %d:\n", count++);
		for(i=0; i<32; i++){
			for(j=0; j<32; j++) con[i][j]=0; 
		}
		total=0;
		for(k=0; k<m; k++){
			scanf("%s%s",name1,name2);
			for(i=0; i<total; i++)
				if(strcmp(name[i],name1)==0) break;
			for(j=0; j<total; j++)
				if(strcmp(name[j],name2)==0) break;
			if(i>=total && j>=total){
				strcpy(name[total++],name1);
				strcpy(name[total++],name2);
				con[total-2][total-1]=1;
			}
			else if(i>=total){
				strcpy(name[total++],name1);
				con[total-1][j]=1;
			}
			else if(j>=total){
				strcpy(name[total++],name2);
				con[i][total-1]=1;
			}
			else con[i][j]=1;
		}
		for(i=0; i<total; i++) group[i]=-1;
		for(k=0; k<total; k++){                   /*Floyd-Warshall*/
			for(i=0; i<total; i++){
				for(j=0; j<total; j++){
					if(con[i][k]&&con[k][j]&&i!=j)
						con[i][j]=1;
				}
			}
		}
		for(i=0; i<total; i++){
			for(j=i+1; j<total; j++){
				if(con[i][j]&&con[j][i]){
					if(group[i]==-1 && group[j]==-1) group[j]=i;
					else if(group[j]==-1) group[j]=group[i];
					else if(group[i]==-1) group[i]=group[j];
					else{
						if(group[i]<group[j]) group[j]=group[i];
						else group[i]=group[j]; 
					}
				}
			}
		}
		for(i=0; i<total; i++){
			if(group[i]==-1){
				index=i;
				printf("%s",name[i]);
				for(j=0; j<total; j++)
					if(group[j]==index) printf(", %s", name[j]);
				printf("\n"); 
			}
		}
	}
	return 0;
}
