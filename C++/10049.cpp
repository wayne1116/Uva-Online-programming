#include<iostream>
using namespace std;
int dp[1000000];
int func(int l, int r, int target)  //¨Ï¥Îbinary search 
{
	int i=0, middle;
	while(l<=r){
		middle=(l+r)/2;
		if(dp[middle]>=target) r=middle-1;
		else l=middle+1;
		//cout << middle << endl;
	}
	return l+1; 
}
int main()
{
	int i, a;
	dp[0]=1; //1
	dp[1]=3; //2
	dp[2]=5; //3
	for(i=3; i<700000; i++)dp[i]=dp[i-1]+func(0,i,i+1);
	while(cin>>a&&a){
		cout << func(0,700000,a) << endl;	
	}
	return 0;
}
