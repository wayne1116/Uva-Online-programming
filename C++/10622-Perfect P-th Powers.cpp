#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long num, flag, limit, temp, i, count=0;
	while(cin>>num&&num){
		flag=0;
		if(num<0){
			flag=1;
			num=-num;
		}
		
		limit=sqrt(num);
		for(i=2; i<=limit; i++){
			temp=num; count=0;
			while(temp%i==0){
				temp/=i;
				++count;
			}
			if(temp==1){
				if(flag==0) cout << count << endl; 
				else{
					if(count%2==1) cout << count << endl; 
					else{
						while(count%2==0) count/=2;
						cout << count << endl;
					}
				}
				break;
			}
		}
		if(i>limit) cout << 1 << endl;
	}
	return 0;
}
