#include<stdio.h>
#include<stdlib.h>
struct node{
	int l,w,h;
};
int cmp(const void *x, const void *y)
{
	return ((struct node *)x)->l-((struct node *)y)->l;
}
int main()
{
	int a=0, n=0, i=0, max=0, lis[256], j=0, case1=1;
	struct node lnode[256];
	while(scanf("%d",&a)&&a){
		n=0;
		for(i=0; i<a; i++){
			scanf("%d%d%d",&lnode[n].l,&lnode[n].w,&lnode[n].h);
			lnode[n+1].l=lnode[n+2].w=lnode[n+3].h=lnode[n+4].w=lnode[n+5].h=lnode[n].l;
			lnode[n+1].h=lnode[n+2].h=lnode[n+3].w=lnode[n+4].l=lnode[n+5].l=lnode[n].w;
			lnode[n+1].w=lnode[n+2].l=lnode[n+3].l=lnode[n+4].h=lnode[n+5].w=lnode[n].h;
			n+=6;
		}
		qsort(lnode,n,sizeof(struct node), cmp);
		for(i=0; i<n; i++) lis[i]=lnode[i].h;
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				if(((lnode[i].l<lnode[j].l)&&(lnode[i].w<lnode[j].w))||((lnode[i].l<lnode[j].w)&&(lnode[i].w<lnode[j].l)) )
					lis[j]=(lis[j]>lis[i]+lnode[j].h)?(lis[j]):(lis[i]+lnode[j].h);
			}
		}
		max=0;
		for(i=0; i<n; i++){
			if(max<lis[i]) max=lis[i];
		}
		printf("Case %d: maximum height = %d\n", case1++, max);
	}
	return 0;
}
