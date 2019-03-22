#include<iostream>
using namespace std;
int main()
{
	int i=0, j=0, n=0, a=0, div=0;
	int result[1024];
	cin >> a;
	while(a--){
		cin >> n;
		if(n/10==0) cout << n << endl;
		else{
			div=9; i=0;
			while(div>1 && n>1){
				if(n%div==0){
					result[i++]=div; 
					n/=div; 
				}
				else div--;
			}
			if(n==1) for(j=i-1; j>=0; j--) cout << result[j];
			else cout << -1;
			cout << endl;
		} 
	} 
	return 0;
}
