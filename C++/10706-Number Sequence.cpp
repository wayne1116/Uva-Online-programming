#include<iostream>
using namespace std;
int main()
{
	long long a, n, move, temp, cnt, len;
	cin >> a;
	while(a--){
		cin >> n;
		move=cnt=len=0;
		while(move<n){     //先找到最遠的邊界 
			temp=++cnt;
			while(temp){
				++len;
				temp/=10;
			}
			move+=len;
		}
		temp=cnt;
		while(move>n){    //再從最遠的邊界往前找 
			move--;
			temp/=10;
			if(temp==0){
				--cnt;
				temp=cnt;
			}
		}
		cout << temp%10 << endl;
		
	}
	return 0;
}
