#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a=0, i=0, row=0, col=0, n=0;
	int temp1[50001], temp2[50001];
	cin >> a;
	while(a--){
		cin >> row >> col >> n;
		for(i=0; i<n; i++){
			cin >> temp1[i] >> temp2[i];
		}
		sort(temp1,temp1+n);
		sort(temp2,temp2+n);
		cout << "(Street: "<< temp1[(n-1)/2] << ", Avenue: "<< temp2[(n-1)/2] << ")" << endl; 
	}
	return 0;
}
