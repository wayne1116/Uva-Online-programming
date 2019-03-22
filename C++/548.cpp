#include<stdio.h>
#include<stdlib.h>
int min1, index, flag[10001], post[10001], in[10001], order[10001], n;
char line1[10000000], line2[10000000];
int count;
void rec(int cur, int start, int end, int value)
{
	int i=0;
	if(cur<0) return;
	if(end-start==1){
		flag[cur]=1;
		value+=post[cur];
		if(value<min1){
			index=post[cur];
			min1=value;
		}
		else if(value==min1 && post[cur]<index) index=post[cur];
	}
	else if(end-start>1){
		flag[cur]=1;
		for(i=n-1; i>=0; i--) if(flag[i]==0) break;
		rec(i,order[post[cur]]+1, end, value+post[cur]);
		for(i=n-1; i>=0; i--) if(flag[i]==0) break;
		rec(i,start,order[post[cur]],value+post[cur]);
	}
}
int main()
{
	char *ptr;
	int i=0;
	while(fgets(line1,1000000,stdin)!=NULL){
		fgets(line2,1000000,stdin);
		ptr=line1; in[0]=atoi(ptr); n=1;
		while(*ptr){
			if(*ptr==' ') in[n++]=atoi(ptr);
			ptr++;
		}
		ptr=line2; post[0]=atoi(ptr); i=1;
		while(*ptr){
			if(*ptr==' ') post[i++]=atoi(ptr);
			ptr++;
		}
		for(i=0; i<n; i++) order[in[i]]=i;
		for(i=0; i<=10000; i++) flag[i]=0;
		min1=2147483647; index=2147483647; count=0;
		rec(n-1,0,n,0);
		printf("%d\n", index);
	}
	return 0;
}
