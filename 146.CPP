#include<iostream>
#include<queue>
#include<cstring>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
using namespace std;
int main()
{
	char line[1024], temp;
	int len=0, state=0, i=0, j=0, k=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	
	while(cin>>line){
		if(line[0]=='#') break;
		len=strlen(line); state=1;
		for(i=len-2; i>=0; i--){
			for(j=len-1; j>i; j--){
				if(line[i]<line[j]){
					swap(line[i], line[j], temp);
					for(k=i+1; k<len; k++) pq.push(line[k]);
					for(k=i+1; k<len; k++){
						line[k]=pq.top();
						pq.pop();
					}
					line[k]='\0';
					cout << line << endl;
					state=0;
					break;
				}
			}
			if(!state) break;
		}
		if(state) cout << "No Successor" << endl;
	}
	return 0;
}
