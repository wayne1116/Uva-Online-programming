#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char line[1024];
	int a=0, n=0, m=0, i=0, j=0;
	cin >> a;
	while(a--){
		cin >> n >> m;
		for(i=0; i<n-m; i++) line[i]='0';
		for(j=i; j<n; j++) line[j]='1';
		line[j]='\0'; cout << line << endl;
		while(next_permutation(line,line+n)) cout << line << endl;
		if(a) cout << endl;
	} 
	return 0;
}
