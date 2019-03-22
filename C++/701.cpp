#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long num, count, temp, lower, upper;
	while(cin>>num){
		count=0; temp=num;
		while(temp>0){
			temp/=10;
			++count;
		}
		++count;
		while(1){
			lower=(int)(log2(num)+count*log2(10));   //n*10^i<2^E<(n+1)*10^i;
			upper=(int)(log2(num+1)+count*log2(10));
			if(lower<upper){
				cout << upper << endl;
				break;
			}
			++count;
		}
	}
	return 0;
}
