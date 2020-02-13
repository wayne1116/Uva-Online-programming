#include<iostream>
#include<set>
using namespace std;
set<double> set1;
int count;
int num[500001]={1}, den[500001]={1};
void check(double &x, double &y)
{
	double temp;
	if(x!=0){
		temp=y/x;
		if(!set1.count(temp)){
			num[count]=y; den[count]=x;
			set1.insert(temp);
			++count;
		}
	}
}
int main()
{
	int n=0, step, i=0, re1, re2;
	double x=0, y=0;
	x=y=1; count=1; step=2;
	set1.insert(1);
	while(count<=500000){
		for(i=0; i<step && count<=500000; i++){
			--y;
			check(x,y);
		}
		for(i=0; i<step && count<=500000; i++){
			--x;
			check(x,y);
		}
		for(i=0; i<step+1 && count<=500000; i++){
			++y;
			check(x,y);
		}
		for(i=0; i<step+1 && count<=500000; i++){
			++x;
			check(x,y);
		}
		step+=2;
	}
	while(cin>>n){
		re1=den[n]>0?(num[n]):(num[n]*-1);
		re2=den[n]>0?(den[n]):(den[n]*-1);
		cout << re1 << " / " << re2 << endl;
	}
	return 0;
}
