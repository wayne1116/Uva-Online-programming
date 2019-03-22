#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char line1[32], line2[32], loca;
int flag[32], len;
void rec(int start, int end, int step)
{
	int i=0, j=0;
	if(end-start==1) {
		printf("%c",line2[start]);
		flag[line2[start]-65]=1;
	}
	else if(start<end){
		for(i=start; i<end; i++){
			if(line2[i]==line1[step]) break;
		}
		flag[line2[i]-65]=1;
		rec(start,i,step+1);
		for(j=0; j<len; j++) if(flag[line1[j]-65]==0) break;
		rec(i+1,end,j);
		printf("%c",line2[i]);
	}
}
int main()
{
	int i=0, j=0;
	while(scanf("%s%s",line1,line2)!=EOF){
		len=strlen(line2);
		for(i=0; i<26; i++) flag[i]=0;
		for(i=0; i<len; i++){
			if(line1[0]==line2[i]) break;
		}
		flag[line2[i]-65]=1;
		rec(0,i,1);
		for(j=0; j<len; j++) if(flag[line1[j]-65]==0) break;
		rec(i+1,len,j);
		printf("%c\n", line2[i]);
	}
	return 0;
}
