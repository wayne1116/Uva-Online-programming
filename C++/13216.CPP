#include<stdio.h>
#include<string.h>
int main()
{
	int i=0, a=0, deter=0, len=0;
	int result[]={56,96,36,76,16};
	char line[1024];
	scanf("%d",&a);
	while(a--){
		scanf("%s",line);
		len=strlen(line);
		if(len==1 && line[0]=='0') printf("1\n");
		else if(len==1 && line[0]=='1') printf("66\n");
		else{
			if(line[len-1]-48>=2) deter=line[len-1]-48-2;
			else if(line[len-1]-48==1) deter=9;
			else deter=8;
			printf("%d\n", result[deter%5]);
		}
	}
	return 0;	
} 
