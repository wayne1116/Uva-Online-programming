#include<iostream>
using namespace std;
int x, y;
int gcd(int a, int b)
{
	int temp, result;
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	result=gcd(b,a%b);
	temp=x;
	x=y;
	y=temp-(a/b)*y;
	return result;
}
int main()
{
	int a, b, result;
	while(cin>>a>>b){
		result=gcd(a,b);
		cout << x << " " << y << " " << result << endl; 
	} 
	return 0;
}
