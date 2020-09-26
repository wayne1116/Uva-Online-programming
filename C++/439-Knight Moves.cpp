#include<iostream>
#include<queue>
using namespace std;
int main()
{
	char line1[128], line2[128];
	int x1=0, x2=0, y1=0, y2=0, size=0, step=0, i=0;
	pair<int,int> dir[8], temp;
	queue<pair<int,int> > qu;
	 
	dir[0]=pair<int,int>(1,-2); dir[1]=pair<int,int>(2,-1);
	dir[2]=pair<int,int>(1,2); dir[3]=pair<int,int>(2,1);
	dir[4]=pair<int,int>(-2,1); dir[5]=pair<int,int>(-1,2);
	dir[6]=pair<int,int>(-2,-1); dir[7]=pair<int,int>(-1,-2);
	while(cin>>line1){
		cin >> line2;
		x1=line1[0]-97; y1=line1[1]-49;
		x2=line2[0]-97; y2=line2[1]-49;
		qu.push(pair<int,int>(x1,y1));
		step=0;
		while(true){
			size=qu.size();
			while(size--){
				temp=qu.front(); qu.pop();
				if(temp.first==x2 && temp.second==y2) break;
				for(i=0; i<8; i++){
					if(temp.first+dir[i].first>=0 && temp.second+dir[i].second>=0 && temp.first+dir[i].first<8 && temp.second+dir[i].second<8) 
						qu.push(pair<int,int>(temp.first+dir[i].first,temp.second+dir[i].second));
				}
			}
			if(temp.first==x2 && temp.second==y2) break;
			step++;
		}	
		cout << "To get from " << line1 << " to " << line2 << " takes " << step << " knight moves."<< endl;
		while(!qu.empty()) qu.pop();
	}
	return 0;
}
