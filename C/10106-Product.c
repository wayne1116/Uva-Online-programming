#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char line1[1024], line2[1024];
	int len1, len2, i=0, num=0, carry=0, j=0, n=0, m=0, result[2048];
	while(scanf("%s%s",line1,line2)!=EOF){
		len1=strlen(line1)-1; len2=strlen(line2)-1;
		for(i=0; i<2048; i++) result[i]=0;
		for(i=len1, n=0; i>=0; i--, n++){
			num=line1[i]-48;
			if(num!=0){
				for(j=len2, m=0; j>=0; j--, m++) result[n+m]=result[n+m]+num*(line2[j]-48);
			}
		}
		carry=0;
		for(i=0; i<2048; i++){
			result[i]+=carry;
			carry=result[i]/10;
			result[i]%=10;
		}
		for(i=2047; i>=0; i--){
			if(result[i]!=0) break;
		}
		if(i<0) printf("0");
		else for(j=i; j>=0; j--) printf("%d",result[j]);
		printf("\n");
	}
	return 0;
}
