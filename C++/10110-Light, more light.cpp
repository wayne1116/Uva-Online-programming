#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a, i, count, limit;
	while(cin>>a&&a){                   //因為只有奇數個因數才會使燈泡亮，而能產生奇數個因數只有完全平方數 
		limit=sqrt(a);
		if(limit*limit==a) cout << "yes";
		else cout << "no";
		cout << endl;
	}
	return 0;
}
