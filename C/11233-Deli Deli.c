#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char word1[32];
	char word2[32];
};
int main()
{
	struct node lnode[32];
	int a,b,i,j,len;
	char line[32];
	while(scanf("%d%d", &a, &b)!=EOF){
		for(i=0; i<a; i++){
			scanf("%s %s", lnode[i].word1, lnode[i].word2);
		}
		for(i=0; i<b; i++){
			scanf("%s", line);
			for(j=0; j<a; j++){
				if(strcmp(lnode[j].word1,line)==0){
					printf("%s\n", lnode[j].word2);
					break;
				}
			}
			if(j==a){
				len=strlen(line)-1;
				if(line[len]=='y' && (line[len-1]=='a' || line[len-1]=='i' || line[len-1]=='o' || line[len-1]=='e' || line[len-1]=='u')){
					printf("%ss\n", line);
				}
				else if(line[len]=='y'){
					line[len]='\0';
					printf("%sies\n", line);
				}
				else if(line[len]=='o' || line[len]=='s' || line[len]=='x'){
					printf("%ses\n", line);
				}
				else if(line[len]=='h' && (line[len-1]=='s' || line[len-1]=='c')){
					printf("%ses\n", line);
				}
				else{
					printf("%ss\n", line);
				}
			}
		}
	}
	return 0;
}
