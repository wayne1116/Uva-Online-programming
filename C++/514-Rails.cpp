#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
char line[1000000];
int main()
{
	int n=0, i=0, j=0, round=0, count=0, num[1024];
	stack<int> sta;
	bool flag=false;
	char *ptr;
	while(cin>>n && n){
		cin.ignore();
		while(cin.getline(line,1000000)){
			if(line[0]=='0') break;
			ptr=line; num[0]=atoi(ptr); count=1;
			while(*ptr){
				if(*ptr==' '){
					ptr++;
					num[count++]=atoi(ptr);
				}
				ptr++;
			}
			i=1; flag=false;
			for(j=0; j<count; j++){
				if(i==num[j]) ++i;
				else{
					while(i<=num[j] && i<=n) sta.push(i++);
					if(sta.size()>0){
						if(sta.top()==num[j]) sta.pop();
						else{
							flag=true;
							break;
						}
					}
					else{
						flag=true;
						break;
					}
				}
			}
			if(flag) cout << "No" << endl;
			else cout << "Yes" << endl;
			while(!sta.empty()) sta.pop();
		}
		cout << endl;
	}
	return 0;
}
