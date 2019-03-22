#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	char line[1024], *ptr;
	int i=0, number=0;
	while(fgets(line,1024,stdin)!=NULL){
		if(line[0]=='\n'){
			cout << endl;
			continue;
		}
		ptr=line;
		while(*ptr){
			if(*ptr>='0' && *ptr<='9'){
				number=0;
				while(*ptr>='0' && *ptr<='9'){
					number+=*ptr-48;
					ptr++;
				}
				if(*ptr=='b') *ptr=' ';
				for(i=0; i<number; i++) cout << *ptr; 
			}
			else cout << endl;
			ptr++;
		}
		
	}
	return 0;
} 
