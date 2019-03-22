#include<iostream>
using namespace std;
int main()
{
	long long num, count[128];
	int i;
	i=1;
	count[0]=9;
	while(i<60){
		if(i%2==1)count[i]=count[i-1]*2;
		else count[i]=count[i-1]*9;
		++i;
	}
	while(cin>>num){
		for(i=0; i<60; i++){
			if(count[i]>=num) break;
		}
		if(i%2==0) cout << "Stan";
		else cout << "Ollie";
		cout <<" wins." << endl;
	}
	return 0;
}
