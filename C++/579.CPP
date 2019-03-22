#include<stdio.h>
#include<stdlib.h>
int main()
{
	float hr=0, min=0, temp1=0, temp2=0, result=0;
	char line[32], *ptr;
	while(scanf("%s", line)){
		ptr=line;
		hr=atoi(ptr);
		while(*ptr&&*ptr!=':') ptr++;
		min=atoi(ptr+1);
		if(hr==0 && min==0) break;
		temp1=min*6;
		temp2=((hr*5*6)+(min/2.0));
		if(temp2>=360) temp2-=360.0;
		if(temp1>temp2) result=(temp1-temp2>(360.0-temp1+temp2))?(360.0-temp1+temp2):(temp1-temp2);
		else result=(temp2-temp1>(360.0-temp2+temp1))?(360-temp2+temp1):(temp2-temp1);
		printf("%.3f\n", result);
	}
	return 0;
}
