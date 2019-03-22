#include<stdio.h>
#include<stdlib.h>
struct node{
	int time, flag, correct, index;
};
int cmp(const void *x, const void *y)
{
	if(((struct node *)x)->correct==((struct node *)y)->correct){
		if(((struct node *)x)->time==((struct node *)y)->time)
			return ((struct node *)x)->index-((struct node *)y)->index;
		return ((struct node *)x)->time-((struct node *)y)->time;
	}
	return ((struct node *)y)->correct-((struct node *)x)->correct;
}
int main()
{
	int a=0, i=0, c=0, p=0, t=0, j=0;
	int problem[128][16];
	char line[1024], com[8];
	struct node contestant[128];
	
	scanf("%d",&a); getchar(); getchar();
	while(a--){
		for(i=0; i<=100; i++){
			for(j=0; j<=9; j++) problem[i][j]=0;
			contestant[i].flag=0; 
			contestant[i].correct=0;
			contestant[i].time=0;
			contestant[i].index=i;
		}
		while(fgets(line,1024,stdin)!=NULL){
			if(line[0]<'1'||line[0]>'9') break;
			sscanf(line,"%d%d%d%s",&c,&p,&t,com);
			contestant[c].flag=1;
			if(problem[c][p]>=0){
				if(com[0]=='I') problem[c][p]+=20;
				else if(com[0]=='C'){
					contestant[c].time+=t+problem[c][p];
					problem[c][p]=-1;
					contestant[c].correct++;
				}
			}
		}
		qsort(contestant, 101, sizeof(struct node), cmp);
		for(i=0; i<=100; i++){
			if(contestant[i].flag) printf("%d %d %d\n", contestant[i].index, contestant[i].correct, contestant[i].time);
		}
		if(a) printf("\n");
	}
	return 0;
}
