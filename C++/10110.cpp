#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a, i, count, limit;
	while(cin>>a&&a){                   //Τ计计穦ㄏ縊獁獹τ玻ネ计计ΤЧキよ计 
		limit=sqrt(a);
		if(limit*limit==a) cout << "yes";
		else cout << "no";
		cout << endl;
	}
	return 0;
}
