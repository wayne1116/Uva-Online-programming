#include<iostream>
#include<sstream>
using namespace std;
const int Max=2147483647;
int main()
{
	string line1, com, line2;
	stringstream ss;
	double a, b;
	while(cin >> line1 >> com >> line2){
		cout << line1 << " "<< com << " "<< line2 << endl;
		ss.str(line1);
		ss>>a;
		ss.clear();
		ss.str(line2);
		ss>>b;
		ss.clear();
		if(a>Max) cout << "first number too big" << endl;
		if(b>Max) cout << "second number too big" << endl;
		if((com[0]=='+' && a+b>Max) || (com[0]=='*'&& a*b>Max)) cout << "result too big" << endl;  
	}
	return 0;
}
