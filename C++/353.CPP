#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char temp1[1024][128];
int main()
{
	char line[128], temp[128];
	int i=0, j=0, len=0, result=0, left=0, right=0, state=0, k=0, l=0, count=0;
	while(scanf("%s",line)!=EOF){
		len=strlen(line); result=0; count=0;
		for(i=1; i<=len; i++){
			for(j=0; j<=len-i; j++){
				left=j; right=j+i-1;
				state=1;
				while(left<right){
					if(line[left]!=line[right]){
						state=0;
						break;
					}
					left++; right--;
				}
				if(state){
					for(l=0, k=j; k<j+i; k++, l++) temp[l]=line[k];
					temp[l]='\0';
					state=1;
					for(k=0; k<count; k++){
						if(strcmp(temp1[k], temp)==0){
							state=0;
							break;
						}
					}
					if(state){
						strcpy(temp1[count++],temp);
						result++;
					}
				}
			}
		}
		printf("The string '%s' contains %d palindromes.\n", line, result);
	}
	return 0;
}
