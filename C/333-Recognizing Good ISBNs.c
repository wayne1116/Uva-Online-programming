#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int s1=0, s2=0, count=0, i=0, num[16], flag=0;
	char line[1024], *ptr, *start;
	while(fgets(line,1024,stdin)!=NULL){
		ptr=line; count=0; flag=0;
		while(*ptr && isspace(*ptr)) ptr++;
		
        	i=strlen(line)-1;
		while(i>=0 && (line[i]=='\n' || line[i]==' ')){
			line[i--]='\0';
		}
		
        	start=ptr;
		while(*ptr){
			if(*ptr>='0' && *ptr<='9')
				num[count++]=*ptr-'0';
			else if(*ptr=='X' && count==9)
				num[count++]=10;
			else if(*ptr!='-' && *ptr!=' '){
				flag=1;
				break;
			}
			ptr++;
		}
		if(count!=10 || flag) printf("%s is incorrect.\n", start);
		else{
			s1=s2=0;
			for(i=0; i<10; i++){
				s1+=num[i];
				s2+=s1; 
			}
			if(s2%11==0) printf("%s is correct.\n", start);
			else printf("%s is incorrect.\n", start);
		}
	}
	return 0;
} 
