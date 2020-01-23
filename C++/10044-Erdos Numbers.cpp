#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
vector<int> vect[100000];
string temp[10000];
int main()
{
	bool flag[100000];
	int result[100000];
	queue<int> qu;
	string str;
	map<string,int> mmap;
	int a, n, m, count1=0, count=0, index=0, i, j, k, begin, len;
	cin >> a;
	while(a--){
		cin >> n >> m;
		cin.ignore();
		mmap["Erdos, P."]=0;
		count1=1;
		for(i=0; i<n; i++){
			getline(cin,str);
			len=str.size();
			begin=0;
			count=0;
			for(j=1; j<len; j++){
				if(str[j-1]=='.'&&(str[j]==','||str[j]==':')){
					for(k=begin; k<j; k++)temp[count]+=str[k];
					if(mmap.find(temp[count])==mmap.end()) mmap[temp[count]]=++count1;
					++count;
					begin=j+2; 
					if(str[j]==':') break;
				}
			}
			for(j=0; j<count; j++){
				for(k=j+1; k<count; k++){
					vect[mmap[temp[j]]].push_back(mmap[temp[k]]);
					vect[mmap[temp[k]]].push_back(mmap[temp[j]]);
				}
			}
			for(j=0; j<count; j++) temp[j].clear();
		} 
		for(i=0; i<=count1; i++){
			flag[i]=true;
			result[i]=-1;
		}
		qu.push(0);
		flag[0]=false;
		result[0]=0;
		while(qu.size()>0){
			begin=qu.front();
			qu.pop();
			len=vect[begin].size();
			for(i=0; i<len; i++){
				if(flag[vect[begin][i]]){
					qu.push(vect[begin][i]);
					flag[vect[begin][i]]=false;
					result[vect[begin][i]]=result[begin]+1;
				}
			}
		}
		cout << "Scenario "<< ++index << endl;
		for(i=0; i<m; i++){
			getline(cin,str);
			cout << str << " ";
			if(mmap.find(str)==mmap.end()) cout << "infinity";
			else if(result[mmap[str]]==-1) cout << "infinity";
			else cout << result[mmap[str]];
			cout << endl; 
		} 
		mmap.clear();
		for(i=0; i<=count1; i++) vect[i].clear();
	}
	return 0;
}
