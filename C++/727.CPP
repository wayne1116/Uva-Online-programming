#include<iostream>
#include<stack>
using namespace std;
int priority(char a)
{
	if(a=='+'||a=='-') return 2;
	else if(a=='*'||a=='/') return 3;
	else if(a=='('||a==')') return 1;
	return -1;
}
int main()
{
	int a=0, temp=0, count=0;
	char oper;
	string line;
	stack<char> sta;
	cin >> a;
	cin.ignore(); cin.ignore(); sta.push('\0');
	while(a--){
		while(true){
			getline(cin,line);
			if(line.length()==0 || !cin) break;
			oper=line[0];
			if(oper=='(') sta.push(oper);
			else if(oper=='+'||oper=='-'||oper=='*'||oper=='/'){
				temp=priority(oper);
				while(priority(sta.top())>=temp){
					cout << sta.top();
					sta.pop();
				}
				sta.push(oper);
			}
			else if(oper==')'){
				while(sta.top()!='('){
					cout << sta.top();
					sta.pop();
				}
				sta.pop();
			}
			else if(oper>='0' && oper<='9') cout << oper;
		}
		while(sta.size()>1){
			cout << sta.top();
			sta.pop();
		}
		cout << endl;
		if(a) cout << endl;
	}
	return 0;
}
