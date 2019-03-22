#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a1, an_1, temp=0, sum=0;
	int n=0, i=0, j=0, a=0;
	cin >> a;
	while(a--){
		cin >> n >> a1 >> an_1;
		sum=0;
		for(i=0, j=n; i<n; i++, j--){
			cin >> temp;
			sum=sum+temp*j;
		}
		cout << fixed << setprecision(2) << ((n*a1+an_1)-2*sum)/(double)(n+1) << endl;
		if(a) cout << endl;
	}
	return 0;
}
