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
		start=ptr;
		ptr=&line[strlen(line)];
		while(ptr!=start && isspace(*ptr)){
			*ptr='\0';
			ptr--;
		}
		ptr=start;
		while(*ptr){
			if(*ptr>='0' && *ptr<='9'){
				num[count]=*ptr-48;
				count++;
			}
			else if(*ptr=='X' && count==9){
				num[count]=10;
				count++;
			}
			else if(*ptr!='-'){
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
