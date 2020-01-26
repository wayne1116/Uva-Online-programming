#include<iostream>
using namespace std;
int main()
{
	double h=0, u=0, d=0, f=0, result=0;
	int day=0;
	bool flag;
	while(cin>>h>>u>>d>>f){
		if(h==0 && u==0 && d==0 && f==0) break;
		result=u; day=1; f=u*f/100.0; flag=true;
		while(1){
			if(result>h) break;
			result=result-d;
			if(result<0){
				flag=false;
				break;
			}
			u=u-f;
			if(u>0)	result+=u;
			day++;
		}
		if(flag) cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl; 
	}
	return 0;
}
