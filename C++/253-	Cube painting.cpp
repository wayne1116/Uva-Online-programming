#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int number[32];
void solv(char *a, int b, int c)
{
	int i=0, temp=0;
	for(i=b; i<c; i++){
		if(i==b) temp=5;
		else if(i==b+1) temp=3;
		else temp=1; 
		if(a[i]=='r'){
			if(a[i+temp]=='r') number[i]=4;
			else if(a[i+temp]=='g') number[i]=3;
			else number[i]=6;
		}
		else if(a[i]=='g'){
			if(a[i+temp]=='r') number[i]=3;
			else if(a[i+temp]=='g') number[i]=2;
			else number[i]=5;
		}
		else{
			if(a[i+temp]=='r') number[i]=6;
			else if(a[i+temp]=='g') number[i]=5;
			else number[i]=8;
		}
	}
}
int main()
{
	char line[32];
	int number1[8];
	int i=0, state=0;
	while(scanf("%s",line)!=EOF){
		solv(line,0,3);
		for(i=0; i<3; i++) number1[i]=number[i];
		solv(line+6,0,3);
		sort(number1,number1+3);
		sort(number,number+3);
		state=1;
		for(i=0; i<3; i++){
			if(number1[i]!=number[i]){
				state=0;
				break;
			}
		}
		if(state) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
} 
