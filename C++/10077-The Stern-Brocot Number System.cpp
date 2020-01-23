#include<iostream>
using namespace std;
double n, m, temp;
void rec(double cur1, double cur2, double lcur1, double lcur2, double rcur1, double rcur2)
{
	double target=cur1/cur2;
	if(target==n/m) return;
	else if(target>temp){
		cout << "L";
		rec(cur1+lcur1,cur2+lcur2,lcur1,lcur2,cur1,cur2);
	}
	else{
		cout << "R";
		rec(cur1+rcur1,cur2+rcur2,cur1,cur2,rcur1,rcur2);
	}
}
int main()
{
	while(cin>>n>>m){
		if(n==1&&m==1) break;
		temp=n/m;
		rec(1,1,0,1,1,0);
		cout << endl;
	}
	return 0;
}
