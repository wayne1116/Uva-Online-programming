#include<iostream>
#include<map> 
#include<stack>
using namespace std;
int main()
{
	int n=0, i=0, row, col, result=0;
	char line[8];
	string line1;
	pair<int,int> pair1[32], pair2;
	map<char,int> mmap;
	stack<pair<int,int> > sta, sta1;
	bool error;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> line >> row >> col;
		mmap[line[0]]=i;
		pair1[i]=pair<int,int>(row, col);
	} 
	cin.ignore();
	while(getline(cin,line1)){
		result=0; error=false;
		for(i=0; i<line1.size(); i++){
			if(line1[i]==')'){
				pair2=sta.top(); sta.pop();
				while(!sta1.empty()) sta1.pop();
				while(pair2.first!='('){
					sta1.push(pair2);
					pair2=sta.top();
					sta.pop();
				}
				pair2=sta1.top(); sta1.pop();
				row=pair2.first; col=pair2.second;
				while(!sta1.empty()){
					pair2=sta1.top(); sta1.pop();
					if(col!=pair2.first){
						error=true;
						break;
					}
					result+=row*col*pair2.second;
					col=pair2.second;
				}
				sta.push(pair<int,int>(row,col));
				if(error) break;
			}
			else if(line1[i]=='(') sta.push(pair<int,int>('(',-1));
			else sta.push(pair<int,int>(pair1[mmap[line1[i]]].first,pair1[mmap[line1[i]]].second));
		}
		if(error){
			cout << "error" << endl;
			while(!sta1.empty()) sta1.pop();
			while(!sta.empty()) sta.pop();
		}
		else{
			pair2=sta.top(); sta.pop();
			row=pair2.first; col=pair2.second;
			while(!sta.empty()){
				pair2=sta.top(); sta.pop();
				result+=row*col*pair2.second; 
			}
			cout << result << endl;
		}
	}
	return 0;
}
