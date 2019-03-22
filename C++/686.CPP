#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	bool flag[32768]={false,false};
	int i=0, limit=0, j=0, count=0, a=0;
	for(i=2; i<32768; i++){
		limit=sqrt(i);
		for(j=2; j<=limit; j++) if(i%j==0) break;
		if(j>limit) flag[i]=true;
		else flag[i]=false;
	}
	while(cin>>a && a){
		limit=a/2;
		count=0;
		for(i=2; i<=limit; i++){
			if(flag[i] && flag[a-i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}
