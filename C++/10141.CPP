#include<stdio.h>
#include<stdlib.h>
struct node{
	char name[128];
	float money;
	int item;
};

int main()
{
	int count=1, i=0, j=0, result=0, a=0, b=0, k=0;
	struct node lnode[1024];
	char line[128], *ptr;
	while(scanf("%d%d",&a,&b)&&a&&b){
		if(k>0) printf("\n");
		fgets(line,128,stdin);
		for(i=0; i<a; i++) fgets(line,128,stdin);
		for(i=0; i<b; i++){
			fgets(lnode[i].name,128,stdin);
			fgets(line,128,stdin);
			ptr=line;
			while(*ptr){
				if(*ptr==' ') break;
				ptr++;
			}
			lnode[i].money=atof(line);
			lnode[i].item=atoi(ptr+1);
			for(j=0; j<lnode[i].item; j++) fgets(line,128,stdin);
		}
		result=0;
		for(i=1; i<b; i++){
			if(lnode[result].item<lnode[i].item) result=i;
			else if(lnode[result].item==lnode[i].item){
				if(lnode[result].money>lnode[i].money) result=i;
			} 
		} 
		printf("RFP #%d\n%s", count++, lnode[result].name);
		k++;
	}
	return 0;
}
