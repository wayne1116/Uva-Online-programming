#include<iostream>
using namespace std;

int main()
{
	int n=0, m=0, i=0, j=0;
	long long result=0;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		if(n-m<m) m=n-m;
		result=1;
		for(i=0; i<m; i++){
			result=result*(n-i)/(i+1);
		}
		cout << result << endl;
	}
	return 0;	
} 
