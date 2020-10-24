#include<iostream>
#include<cstring>
using namespace std;
char line[1000000];
int main()
{
	int n=0, m=0, i=0, len=0, sum=0, money[1024];
	char word[1024][32], *ptr, *find;
	cin >> n >> m;
	for(i=0; i<n; i++) cin >> word[i] >> money[i];
	cin.ignore();
	while(m--){
		sum=0;
		while(cin.getline(line,1000000)){ 
			if(strstr(line,".")!=NULL) break;
			find=strtok(line," ");
			while(find!=NULL){
				for(i=0; i<n; i++) 
					if(strcmp(find,word[i])==0){
						sum+=money[i];
						break;
					}
				find=strtok(NULL," ");
			} 
		}
		cout << sum << endl;
	}
	return 0;	
} 
