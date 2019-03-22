#include<iostream>
#include<cmath>
#define Max 1<<16
using namespace std;
int prime[10000];
int cal(int n, int prim)
{
	int count=0;
	while(n){
		n/=prim;
		count+=n;
	}
	return count;
}
int main()
{
	bool flag;
	int n, m, remain, i, count, limit, j, temp, temp1, count1;
	count=1;
	prime[0]=2;
	for(i=3; i<=Max; i+=2){
		limit=sqrt(i);
		for(j=3; j<=limit; j++){
			if(i%j==0) break;
		}
		if(j>limit) prime[count++]=i;
	}
	
	while(cin>>n>>m){
		//if(n>=m) cout << m << " divides " << n << "!" << endl;
		//else if(n==0) cout << m << " does not divide " << n << "!" << endl;
		//else{
			temp1=m;
			flag=false;
			for(i=0; i<count&&(long long)prime[i]*(long long)prime[i]<=temp1; i++){
				if(temp1%prime[i]==0){
					count1=0;
					while(temp1%prime[i]==0){
						temp1/=prime[i];
						++count1;
					}
					if(cal(n,prime[i])<count1){          //利用質因數的個數來做比較 
						flag=true;
						break;
					} 
				}
			}
			if(flag||(temp1>1&&n<temp1)) cout << m << " does not divide " << n << "!" << endl;
			else cout << m << " divides " << n << "!" << endl;
		//}
	}
	return 0;
}
