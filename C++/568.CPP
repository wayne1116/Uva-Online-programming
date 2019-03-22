#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int num=0, i=0;
	int result[10001]={1,1,2,6,24};
	for(i=5; i<=10000; i++){
		result[i]=result[i-1]*i;
		while(result[i]%10==0) result[i]/=10;
		result[i]=result[i]%100000;
	}
	while(cin>>num){
		cout << setw(5) << num << " -> " << result[num]%10 << endl;
	}
	return 0;
}
