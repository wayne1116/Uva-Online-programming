#include<iostream>
using namespace std;
int main()
{
	string line;
	while(getline(cin,line)){
		int len=line.size();
		for(int i=0; i<len; i++){
			line[i]=line[i]-7;
		}
		cout << line << endl;
	}
	return 0;
}
