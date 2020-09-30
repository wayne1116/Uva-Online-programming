#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double n;
	double p;
	double temp;
	long result;
	int count;
	while((cin >> n >> p)){
		temp=pow(p,1.0/n);
		result=static_cast<long>(temp);
		count=0;
		while(result>0){
			count++;
			result/=10;
		}
		cout << setprecision(count) << temp << endl;
	}
	return 0;
}
