#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a=0, i=0, j=0, count=0, carry=0, len=0, state=0, result[128];
	char line[128];
	scanf("%d",&a);
	while(a--){
		scanf("%s",line);
		count=1;
		while(1){
			len=strlen(line);
			carry=0;
			for(i=0; i<len; i++){
				result[i]=line[i]+line[len-i-1]-96+carry;
				if(result[i]>9){
					result[i]=result[i]%10;
					carry=1;
				}
				else carry=0;
			}
			if(carry==1){
				result[i]=1;
				len++;
			}
			state=1;
			for(i=0; i<len/2; i++){
				if(result[i]!=result[len-1-i]){
					state=0;
					break;
				}
			}
			if(state){
				printf("%d ", count);
				for(i=len-1; i>=0; i--) printf("%d",result[i]);
				printf("\n");
				break;
			}
			for(i=len-1, j=0; i>=0; i--, j++) line[j]=result[i]+48;
			line[j]='\0';
			count++;
		}
	}
	return 0;
} 
