#include<iostream>
using namespace std;
bool prime[10000001];
int main()
{
	int i, a, j;
	for(i=2; i<=10000000; i++) prime[i]=true;
	prime[0]=prime[1]=false;
	for(i=2; i<=10000000; i++){
		if(prime[i]){
			for(j=i+i; j<=10000000; j+=i) prime[j]=false;
		}
	}
	while(cin>>a){
		if(a<8){
			cout << "Impossible." << endl;
			continue;
		}
		else if(a%2==0){
			cout << "2 2 ";
			a-=4;
		}
		else{
			cout << "2 3 ";
			a-=5;
		}
		for(i=2; i<a; i++) if(prime[i]&&prime[a-i]) break;
		cout << i << " " << a-i << endl;
	}
	return 0;
}
