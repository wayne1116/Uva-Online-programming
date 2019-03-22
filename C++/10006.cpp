#include<iostream>
#include<cmath>
using namespace std;
long long n1;
long long mod(long long a, long long n)
{
	long long temp;
	if(n==1) return a;
	else if(n==0) return 1;
	else if(n%2==0){
		temp=mod(a,n/2)%n1;
		return (temp*temp)%n1;
	}
	temp=mod(a,n/2)%n1;
	return (a*temp*temp)%n1;
}
int main()
{
	long long a, j, temp;
	int i, limit, count=1;
	int prime[65000];
	prime[0]=2;
	for(i=3; i<65000; i+=2){
		limit=sqrt(i);
		for(j=3; j<=limit; j+=2){
			if(i%j==0) break;
		}
		if(j>limit) prime[count++]=i;
	}
	while(cin>>a&&a){
		for(i=0; i<count; i++){
			if(prime[i]==a) break;
		}
		if(i<count) cout << a << " is normal." << endl;
		else{
			for(j=2; j<=a-1; j++){
				n1=a;
				temp=mod(j,a);
				if(temp!=j) break;
			}
			if(j>a-1) cout << "The number " << a << " is a Carmichael number." << endl;
			else cout << a << " is normal." << endl;
		}
	}
	return 0;
}
