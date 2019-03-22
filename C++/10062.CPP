#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Node{
	char v;
	int count;
};
bool cmp(Node &x, Node &y)
{
	if(x.count==y.count) return x.v>y.v;
	return y.count>x.count;
}
int main()
{
	char line[1024], *ptr;
	int i=0, j=0;
	Node lnode[512];
	while(fgets(line,1024,stdin)!=NULL){
		if(j>0) printf("\n");
		ptr=line;
		for(i=0; i<256; i++){
			lnode[i].v=i;
			lnode[i].count=0;
		}
		while(*ptr){
			if(*ptr=='\n') break;
			lnode[*ptr].count++;
			ptr++;
		}
		sort(lnode,lnode+256,cmp);
		i=0;
		while(lnode[i].count==0)i++;
		while(i<256){
			printf("%d %d\n", lnode[i].v, lnode[i].count);
			i++;
		}
		j++;
	}
	return 0;
}
