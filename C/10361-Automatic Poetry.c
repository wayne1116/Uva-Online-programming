#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
char temp[4][128];
char *cal(char *p, char chara)
{
	char *temp1=p;
	int n=0;
	while(*temp1!=chara){
		temp[count][n++]=*temp1;
		temp1++;
	}
	temp[count++][n]='\0';
	return temp1+1;
}
int main()
{
	int a=0, i=0;
	char line1[128], line2[128], *ptr=NULL, *start=NULL;
	scanf("%d",&a); getchar();
	while(a--){
		fgets(line1,128,stdin);
		fgets(line2,128,stdin);
		ptr=line1;
		while(*ptr){
			if(*ptr!='>'&&*ptr!='<') printf("%c",*ptr);
			ptr++;
		}
		start=line1; count=0;
		start=cal(start,'<');
		start=cal(start,'>');
		start=cal(start,'<');
		start=cal(start,'>');
		
		ptr=line2;
		while(*ptr){
			if(*ptr=='.') break;
			printf("%c",*ptr);
			ptr++;
		}
		printf("%s%s%s%s",temp[3],temp[2],temp[1],start);
	}
	return 0;
} 
