#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n=0, num[64];
	double result1=0, result2=0;
	while(cin>>n && n){
		result1=n*(n-1)/2;
		result2=0;
		for(int i=0; i<n; i++){
			cin >> num[i];
			for(int j=0; j<i; j++){
				if(gcd(num[j],num[i])==1) result2++;
			}
		}
		if(result2==0) cout <<"No estimate for this data set."<<endl;
		else cout << showpoint<<setprecision(7)<<sqrt(6.0*result1/result2)<<endl;
	}
	return 0;
}
