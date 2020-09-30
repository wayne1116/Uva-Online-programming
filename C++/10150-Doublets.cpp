#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
string str[25143];
vector<int> vect[25143];
bool flag[25143];
int parent[25143];
int main()
{
	int num, i, j, k, size, count, begin, index;
	map<string,int> mmap;
	map<int,string> mmap1;
	queue<int> qu;
	stack<int> sta;
	string line1, line2;
	bool find;
	
	num=0;
	while(getline(cin,str[num])&&str[num].size()>0){
		mmap[str[num]]=num;
		mmap1[num]=str[num];
		++num;
	}
	for(i=0; i<num; i++){
		for(j=+1; j<num; j++){
			size=str[i].size();
			if(size==str[j].size()){
				count=0;
				for(k=0; k<size; k++) if(str[i][k]!=str[j][k]) ++count;
				if(count==1){
					vect[mmap[str[i]]].push_back(mmap[str[j]]);
					vect[mmap[str[j]]].push_back(mmap[str[i]]); 
				}
			}
		}
	}
	index=0;
	while(cin>>line1>>line2){
		if(index++>0) cout << endl;
		if(line1.size()!=line2.size() || mmap.find(line1)==mmap.end()||mmap.find(line2)==mmap.end())
			cout << "No solution." << endl;
		else{
			for(i=0; i<num; i++){flag[i]=true; parent[i]=-1;}
			qu.push(mmap[line1]);
			flag[mmap[line1]]=false;
			//find=false;
			while(qu.size()>0){
				begin=qu.front();
				qu.pop();
				for(auto iter:vect[begin]){
					if(flag[iter]){
						flag[iter]=false;
						parent[iter]=begin;
						//if(iter==mmap[line2]){
						//	find=true;
						//	break;
						//}
						qu.push(iter);
					}
				}
				//if(find) break;
			}
			if(parent[mmap[line2]]!=-1){
				begin=parent[mmap[line2]];
				while(begin!=mmap[line1]){
					sta.push(begin);
					begin=parent[begin];
				}
				cout << line1 << endl;
				while(!sta.empty()){
					cout << mmap1[sta.top()] << endl;
					sta.pop();
				}
				cout << line2 << endl;
			}
			else cout << "No solution." << endl;
			while(!qu.empty()) qu.pop();
		}
	}
	mmap.clear();
	mmap1.clear();
	for(i=0; i<num; i++) vect[i].clear();
	
	return 0;
}
