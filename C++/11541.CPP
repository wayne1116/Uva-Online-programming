#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, number=0, j=1;
	char com, line[1024], *ptr;
	scanf("%d",&a);
	while(a--){
		scanf("%s",line);
		ptr=line;
		printf("Case %d: ", j++);
		while(*ptr){
			if(*ptr>='A' && *ptr<='Z'){
				com=*ptr;
				ptr++;
				number=atoi(ptr);
				for(i=0; i<number; i++) printf("%c",com);
			}
			ptr++;
		}
		printf("\n");
	} 
	return 0;
}
