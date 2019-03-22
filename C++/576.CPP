#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char line[1024], *start, *ptr;
	int len=0, temp=0, count=0, h[3]={5,7,5};
	bool flag=true;
	while(cin.getline(line,1024)){
		if(strcmp(line,"e/o/i")==0) break;
		len=strlen(line);
		line[len]='/'; line[len+1]='\0';
		ptr=line; start=ptr; temp=0;
		while(*ptr){
			if(*ptr=='/'){
				count=0; flag=true;
				while(start!=ptr){
					if(*start=='a'||*start=='e'||*start=='i'||*start=='o'||*start=='u'||*start=='y'){
						if(flag){
							flag=false;
							count++;
						}
					}
					else flag=true;
					start++;
				}
				if(h[temp]!=count){
					cout << temp+1 << endl;
					break;
				}
				temp++;
				start=ptr+1;
			}
			ptr++;
		}
		if(*ptr=='\0') cout << "Y"<<endl;
	}
	return 0;
}
