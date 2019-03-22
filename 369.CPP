#include<iostream>
using namespace std;
int main()
{
	long long result=0, n=0, m=0;
	int i=0;
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		cout << n << " things taken " << m << " at a time is ";
		if(m==0||n-m==0) cout << 1;
		else if(m==1 || n-m==1) cout << n; 
		else{
			m=n-m>m?m:n-m;
			result=n*(n-1);
			n=n-2;
			for(i=2; i<m; i++, n--) result=result*n/i;
			cout << result/i;
		}
		cout << " exactly." << endl;
	}
}
