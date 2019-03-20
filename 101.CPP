#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
int main()
{
	stack<int> st[32], temp;
	int i=0, a=0, tar1=0, tar2=0, u=0, locat=0;
	char c, line[1024], *ptr, com1, com2;
	int loc[32];
	 
	while(cin>>a){
		for(i=0; i<a; i++){
			while(!st[i].empty()) st[i].pop();
			st[i].push(i);
			loc[i]=i;
		}
		cin >> c;
		while(fgets(line,1024,stdin)){
			ptr=line; com1=*ptr;
			if(*ptr=='q') break;
			while(!isdigit(*ptr)) ptr++;
			tar1=atoi(ptr);
			while(*ptr!=' ') ptr++;
			ptr+=2; com2=*ptr;
			while(*ptr!=' ') ptr++;
			tar2=atoi(ptr+1);
			if(loc[tar1]!=loc[tar2]){
				if(com1=='m'){
					locat=loc[tar1];
					while(!st[locat].empty()){
						u=st[locat].top();
						st[locat].pop();
						if(u==tar1) break;
						st[u].push(u);
						loc[u]=u;
					}
					if(com2=='n'){
						locat=loc[tar2];
						while(!st[locat].empty()){
							u=st[locat].top();
							if(u==tar2) break;
							st[locat].pop();
							st[u].push(u);
							loc[u]=u;
						}
					}
					st[loc[tar2]].push(tar1);
					loc[tar1]=loc[tar2];
				}
				else{
					locat=loc[tar1];
					while(!st[locat].empty()){
						u=st[locat].top();
						st[locat].pop();
						temp.push(u);
						if(u==tar1) break;
					}
					if(com2=='n'){
						locat=loc[tar2];
						while(!st[locat].empty()){
							u=st[locat].top();
							if(u==tar2) break;
							st[locat].pop();
							st[u].push(u);
							loc[u]=u;
						}
					}
					while(!temp.empty()){
						st[loc[tar2]].push(temp.top());
						loc[temp.top()]=loc[tar2];
						temp.pop();
					}
				}
			}
		}
		for(i=0; i<a; i++){
			cout << i << ":";
			if(!st[i].empty()){
				cout << " ";
				while(!st[i].empty()){
					temp.push(st[i].top());
					st[i].pop();
				}
				while(temp.size()>1){
					cout << temp.top() << " ";
					temp.pop();
				}
				cout << temp.top();
				temp.pop();
			}
			cout << endl;
		}
	}
	return 0;
}
