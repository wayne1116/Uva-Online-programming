#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char line[1024];
	int len=0, start=0, end=0, i=0, j=0;
	while(cin.getline(line,1024)){
		len=strlen(line);
		start=0;
		for(i=0; i<len+1; i++){
			if(line[i]==' '|| line[i]=='\0'){
				end=i-1;
				for(j=end; j>=start; j--) cout << line[j];
				if(line[i]=='\0'){
					cout << endl;
					break;
				}
				cout << " ";
				start=i+1;
			}
		}
	}
	return 0;
}
