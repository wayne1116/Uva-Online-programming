#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n, a, b, count=0, i=0, j=0, temp=0, len=0, num=0, result=0, case1=1;
	map<int,int> mmap;
	map<int,int>::iterator iter;
	queue<int> qu;
	vector<int> vect[10000];
	bool flag[10000];
	while(cin>>n&&n){
		count=0;
		while(n--){
			cin >> a >> b;
			iter=mmap.find(a);
			if(iter==mmap.end()){
				mmap[a]=count;
				vect[count].push_back(b);
				count++;
			} 
			else vect[iter->second].push_back(b);
			iter=mmap.find(b);
			if(iter==mmap.end()){
				mmap[b]=count;
				vect[count].push_back(a);
				count++;
			}
			else vect[iter->second].push_back(a);
		}
		while(cin >> a >> b){
			if(a==0 && b==0) break;
			for(i=0; i<count; i++) flag[i]=false;
			while(!qu.empty()) qu.pop();
			iter=mmap.find(a);
			if(iter!=mmap.end()){
				flag[iter->second]=true;
				qu.push(iter->second);
				temp=b+1;
				while(temp--){
					len=qu.size();
					while(len--){
						num=qu.front();
						qu.pop();
						flag[num]=true;
						for(i=0; i<vect[num].size(); i++){
							if(flag[mmap[vect[num][i]]]==false) qu.push(mmap[vect[num][i]]);
						}
					}
				}
			}
			result=0;
			for(i=0; i<count; i++) if(flag[i]==false) ++result;
			cout << "Case " << case1++ << ": " << result << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl; 
		}
		for(i=0; i<count; i++)vect[i].clear();
		mmap.clear();
	} 
	return 0;
}
