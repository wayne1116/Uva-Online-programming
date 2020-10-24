#include<stdio.h>
#include<stdio.h>
#include<string.h>
char line[1000000];
int fail[1000000];
int failed()                     /*KMP*/
{
	int len=strlen(line);
	int i=0, j=0;
	fail[0]=-1;   /*先將line[0]設為-1 */ 
	for(i=1; i<len; i++){      /*目標為要尋找的字串*/ 
		j=fail[i-1];
		while(j>=0 && line[j+1]!=line[i]) j=fail[j];
		if(line[i]==line[j+1]) fail[i]=j+1;
		else fail[i]=-1;
	}
	return fail[len-1];
}
int main()
{
	int len, result;
	while(scanf("%s",line)&&line[0]!='.'){
		len=strlen(line);
		result=len-failed()-1;
		printf("%d\n", len%result==0?len/result:1);
	}
	return 0;
}
