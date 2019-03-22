#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
int main()
{
	char line[1024];
	int i=0, j=0, len=0, state=0, number=0, count=0, flag=0, carry=0;
	int temp[1024], temp1[1024], temp2;
	while(scanf("%s",line)!=EOF){
		for(i=15; i>1; i--){
			if(i<15) printf(" ");
			len=strlen(line); state=1;
			for(j=0; j<len; j++){
				if(line[j]>='A' && line[j]<='E') number=line[j]-55;
				else number=line[j]-48;
				if(number>=i){
					state=0;
					break;
				} 
				temp[len-j-1]=number;
			} 
			if(state){
				count=0;
				while(count<=100){
					flag=1;
					for(j=0; j<len/2; j++){
						if(temp[j]!=temp[len-j-1]){
							flag=0;
							break;
						}
					}
					if(flag){
						printf("%d", count);
						break;
					}
					count++;
					for(j=0; j<len; j++) temp1[j]=temp[len-1-j];
					carry=0;
					for(j=0; j<len; j++){
						temp[j]+=temp1[j]+carry;
						if(temp[j]>=i){
							carry=temp[j]/i;
							temp[j]=temp[j]%i;
						}
						else carry=0;
					}
					if(carry!=0) temp[len++]=carry;
					for(j=0; j<len/2; j++) swap(temp[j], temp[len-j-1], temp2);
				}
			}
			else printf("?");
		}
		printf("\n");
	}
	return 0;
}
