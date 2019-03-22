#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char line[1024], temp1[1024], temp2[1024];
	int len=0, count=0, state=0, flag=0, k=0, l=0;
	int i=0, j=0, start1=0, start2=0, result1=0, result2=0;
	while(scanf("%s",line)!=EOF){
		len=strlen(line); count=0; state=0;
		for(i=3; i<5; i++){                      /*只需判斷長度3和4的子字串*/ 
			for(j=0; j<=len-i; j++){
				start1=j; start2=j+i-1; flag=1;
				while(start1<start2){
					if(line[start1]!=line[start2]){
						flag=0;
						break;
					}
					start1++;
					start2--;
				}
				if(flag){
					if(count==0){
						result1=j;
						result2=j+i-1;
						for(k=0; k<i-1; k++) temp1[k]='\0';
						for(k=0, l=result1; l<=result2; l++, k++) temp1[k]=line[l];
						temp1[k]='\0';
						count++;
					}
					else{
						for(k=0; k<i-1; k++) temp2[k]='\0';
						for(k=0, l=j; l<=j+i-1; l++, k++) temp2[k]=line[l];
						temp2[k]='\0';
						if((result1<j || result2>j+i-1)&&strstr(temp2,temp1)==NULL){
							printf("%s\n", line);
							state=1;
							break;
						}
					}
				}
			}
			if(state) break;
		}
	}
	return 0;
}
