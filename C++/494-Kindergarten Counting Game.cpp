#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
int main()
{
	char line[1024], *ptr;
	int count=0;
	
	while(fgets(line,1024,stdin)!=NULL){
		ptr=line; count=0;
		while(*ptr){
			if(isalpha(*ptr)){
				count++;
				while(isalpha(*ptr)) ptr++;
			}
			ptr++;
		}
		cout << count << endl;
	}
	return 0;
}
