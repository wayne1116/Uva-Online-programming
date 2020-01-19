#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int day;
	int cost;
	int index;
};
bool cmp(struct Node &x, struct Node &y)
{
	if(x.cost*y.day==y.cost*x.day) return y.index>x.index;
	return x.cost*y.day>y.cost*x.day;
}
int main()
{
	int a, n, i, j, total, index, Max;
	struct Node lnode[1024];
	string str;
	
	cin >> a;
	cin.ignore();
	while(a--){
		getline(cin,str);
		cin >> n;
		for(i=0; i<n; i++){
			cin >> lnode[i].day >> lnode[i].cost;
			lnode[i].index=i+1;
		}
		sort(lnode,lnode+n,cmp); 
		for(i=0; i<n-1; i++){
			cout << lnode[i].index << " ";
		}
		cout << lnode[i].index << endl;
		if(a) cout << endl;
	}
	return 0;
}
