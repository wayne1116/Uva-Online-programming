#include<iostream>
using namespace std;
int main()
{
	long long a, n, move, temp, cnt, len;
	cin >> a;
	while(a--){
		cin >> n;
		move=cnt=len=0;
		while(move<n){     //�����̻������ 
			temp=++cnt;
			while(temp){
				++len;
				temp/=10;
			}
			move+=len;
		}
		temp=cnt;
		while(move>n){    //�A�q�̻�����ɩ��e�� 
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
