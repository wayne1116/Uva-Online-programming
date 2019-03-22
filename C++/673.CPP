#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int a=0, i=0;
	string line;
	char ch;
	stack<char> sta;
	bool flag;
	cin >> a;
	getchar();
	while(a--){
		getline(cin,line);
		flag=true;
		for(i=0; i<line.size(); i++){
			if(line[i]=='[' || line[i]=='(') sta.push(line[i]);
			else if(line[i]==']' || line[i]==')'){
				if(sta.empty()){
					flag=false;
					break;
				}
				ch=sta.top();
				sta.pop();
				if(line[i]==')' && ch!='('){
					flag=false;
					break;
				}
				else if(line[i]==']' && ch!='['){
					flag=false;
					break;
				}
			}
		}
		if(flag && sta.empty()) cout <<"Yes"<<endl;
		else cout << "No" << endl;
		while(!sta.empty()) sta.pop(); 
	}
	return 0;
}
