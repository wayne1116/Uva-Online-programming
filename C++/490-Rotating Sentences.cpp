#include<iostream>
#include<cstring>
using namespace std;
char line[128][128];
int main()
{
	int i=0, max=0, j=0, k=0;
	while(cin.getline(line[i],1024)){
		if(max<strlen(line[i])) max=strlen(line[i]);
		i++;
	}
	for(j=0; j<max; j++){
		for(k=i-1; k>=0; k--){
			if(j<strlen(line[k])) cout << line[k][j];
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
