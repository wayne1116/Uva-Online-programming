#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char result[128][128], line[128];
	int i, j, len, len1, locx, locy;
	for(i=0; i<128; i++){
		for(j=0; j<128; j++) result[i][j]='\0';
	}
	while(scanf("%d %s",&len,line)!=EOF){
		if(len==0) break;
		for(i=0; i<127; i++){
			for(j=0; j<127; j++) result[i][j]=' ';
		}
		len1=strlen(line);
		for(i=0; i<len1; i++){
			locx=i*(len+3);
			locy=0;
			if(line[i]!='1'&&line[i]!='4'){
				for(j=0; j<len; j++) result[locy][locx+j+1]='-';
			}
			if(line[i]!='5'&&line[i]!='6'){
				for(j=0; j<len; j++) result[locy+j+1][locx+len+1]='|';
			}
			if(line[i]!='1'&&line[i]!='2'&&line[i]!='3'&&line[i]!='7'){
				for(j=0; j<len; j++) result[locy+j+1][locx]='|';
			}
			if(line[i]!='1'&&line[i]!='7'&&line[i]!='0'){
				for(j=0; j<len; j++) result[locy+len+1][locx+j+1]='-';
			}
			if(line[i]=='2'||line[i]=='6'||line[i]=='8'||line[i]=='0'){
				for(j=0; j<len; j++) result[locy+len+2+j][locx]='|';
			}
			if(line[i]!='2'){
				for(j=0; j<len; j++) result[locy+len+2+j][locx+len+1]='|';
			}
			if(line[i]!='1'&&line[i]!='4'&&line[i]!='7'){
				for(j=0; j<len; j++) result[2*len+2][locx+1+j]='-';
			}
		}
		for(i=0; i<2*len+3; i++){
			result[i][len1*(len+3)-1]='\0';
			printf("%s\n", result[i]);
		}
		printf("\n");
	}
	return 0;
}
