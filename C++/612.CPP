#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	string line;
	int unsort, id;
};
bool cmp(Node &x, Node &y)
{
	if(x.unsort==y.unsort) return y.id>x.id;
	return x.unsort<y.unsort;
}
int main()
{
	int a=0, i=0, j=0, k=0, temp=0, m=0, n=0, count=0;
	string line;
	Node lnode[128]; 
	cin >> a;
	while(a--){
		if(count>0) cout << endl;
		cin >> m >> n;
		for(i=0; i<n; i++){
			cin >> line;
			temp=0;
			for(j=0; j<m; j++){
				for(k=j+1; k<m; k++){
					if(line[j]>line[k]) temp++;
				}
			}
			lnode[i].line=line;
			lnode[i].unsort=temp;
			lnode[i].id=i;
		}
		sort(lnode,lnode+n,cmp);
		for(i=0; i<n; i++) cout << lnode[i].line << endl;
		count++;
	}
	return 0;
} 
