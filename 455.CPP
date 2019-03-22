#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a=0, i=0, len=0;
	char line[128], *ptr, str[128], *find;
	scanf("%d",&a);
	while(a--){
		scanf("%s",line);
		len=strlen(line)/2;
		for(i=0; i<len; i++){
			str[i]=line[i]; str[i+1]='\0';
			ptr=line+i+1;
			while((find=strstr(ptr,str))!=NULL){
				if(find!=ptr) break;
				ptr=find+i+1;
			}
			if(*ptr=='\0') break; 
		}
		if(*ptr=='\0') printf("%d\n", i+1);
		else printf("%d\n", strlen(line));
		if(a) printf("\n");
	}
	return 0;
}
