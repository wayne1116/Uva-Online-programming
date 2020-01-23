#include<iostream>
#include<cmath> 
using namespace std;
#define Max 1000000
int prime[100000];
int main()
{
	int count=0, i, j, limit, temp, temp1, temp2;
	int a, n, result;
	bool flag;
	prime[0]=2;
	count=1;
	for(i=3; i<Max; i+=2){
		limit=sqrt(i);
		for(j=2; j<=limit; j++) if(i%j==0) break;
		if(j>limit) prime[count++]=i;
	}
	cin >> a;
	while(a--){
		cin >> n;
		++n;
		while(true){
			temp=n;
			result=0;
			flag=false;
			for(i=0; i<count&&temp>=prime[i]; i++)if(temp==prime[i]){flag=true;break;}
			if(flag){
				++n;
				continue;
			}
			for(i=0; i<count&&temp>=prime[i]; i++){
				if(temp%prime[i]==0){
					temp1=prime[i];
					temp2=0;
					while(temp1>0){
						temp2+=temp1%10;
						temp1/=10;
					}
					while(temp%prime[i]==0){
						temp/=prime[i];
						result+=temp2;
					}
				}
			}
			if(temp!=n&&temp>1){
				while(temp){
					result+=temp%10;
					temp/=10;
				}
			}
			temp=n;
			temp1=0;
			while(temp>0){
				temp1+=temp%10;
				temp/=10;
			}
			if(temp1==result){
				cout << n << endl;
				break;
			}
			++n;
		}
	}
	return 0;
} 
