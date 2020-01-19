#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i=0;
	int temp[2048];
	int n2=0, n3=0, n5=0;
	temp[0]=1;
	for(i=1; i<1500; i++){
		while(temp[n2]*2<=temp[i-1]) n2++;
		while(temp[n3]*3<=temp[i-1]) n3++;
		while(temp[n5]*5<=temp[i-1]) n5++;
		temp[i]=min(temp[n2]*2, min(temp[n3]*3,temp[n5]*5));
	}	
	cout << "The 1500'th ugly number is "<< temp[1499] << "." << endl;
	return 0;
} 
