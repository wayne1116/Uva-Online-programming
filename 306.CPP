#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int number[256], count[256], location[256][256];
	int a=0, i=0, b=0, temp=0, start=0, j=0, index=0, len=0, k=0;
	char line[256], result[256];
	while(scanf("%d",&a)&&a){
		for(i=0; i<a; i++) scanf("%d",&number[i]);
		for(i=0; i<a; i++){
			temp=0; start=i;
			count[i]=0;
			while(number[start]-1!=i){
				location[i][temp]=start;
				start=number[start]-1;
				temp++;
			}
			location[i][temp++]=start;
			count[i]=temp;
		}
		while(scanf("%d",&b)&&b){
			getchar();
			cin.getline(line,1024);
			len=strlen(line);
			while(len<a) line[len++]=' ';
			line[len]='\0';	
			for(i=0; i<a; i++){
				index=b%count[i];
				result[location[i][index]]=line[i];
			}
			result[a]='\0';
			printf("%s\n", result);
		}
		printf("\n");
	}
	return 0;
}
