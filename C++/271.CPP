#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	char charact;
	string line;
	int len=0, i=0;
	bool flag;
	stack<char> sta;
	
	while(cin>>line){
		len=line.size(); flag=true;
		while(!sta.empty()) sta.pop();
		for(i=len-1; i>=0; i--){
			if(line[i]>='p' && line[i]<='z') sta.push(line[i]);
			else if(line[i]=='N' && sta.size()>=1);
			else if((line[i]=='C'||line[i]=='D'||line[i]=='E'||line[i]=='I') && sta.size()>=2) sta.pop();
			else{
				flag=false;
				break;
			}
		}
		if(sta.size()==1 && flag) cout << "YES" << endl;
		else cout << "NO"<<endl;
	}
	return 0;
}
