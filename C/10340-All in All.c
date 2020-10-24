#include<stdio.h>
#include<stdlib.h>
char line1[1000000], line2[1000000];
int main()
{
	char *ptr1, *ptr2;
	while(scanf("%s%s",line1,line2)!=EOF){
		ptr1=line1; ptr2=line2;
		while(*ptr1&&*ptr2){
			if(*ptr1==*ptr2) ptr1++;
			ptr2++;
		}
		if(!*ptr1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
