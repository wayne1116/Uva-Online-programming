#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n=0, m=0, i=0, j=0, k=0, max=0, count[21], len=0;
	char word[21][128], line[21][128], temp[128], *ptr, *find;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("Excuse Set #%d\n", ++k);
		for(i=0; i<n; i++){
			scanf("%s",word[i]);
			ptr=word[i];
			while(*ptr){
				*ptr=tolower(*ptr);
				ptr++;
			}
		}
		getchar(); max=0;
		for(i=0; i<m; i++){
			count[i]=0;
			fgets(line[i],128,stdin);
			strcpy(temp,line[i]);
			ptr=temp;
			while(*ptr){
				*ptr=tolower(*ptr);
				ptr++;
			}
			for(j=0; j<n; j++){
				ptr=temp; len=strlen(word[j]);
				while((find=strstr(ptr,word[j]))!=NULL && *ptr && !isdigit(*(find+len)) && !isalpha(*(find+len))){
					count[i]++;
					ptr=find+len;
				}
			}
			if(max<count[i]) max=count[i];
		}
		for(i=0; i<m; i++){
			if(max==count[i]) printf("%s",line[i]); 
		}
		printf("\n");
	}
	return 0;
}
