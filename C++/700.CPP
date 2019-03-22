#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int date,start,end;
};
int main()
{
	int n=0, u=0, differ=0, date=0, len=0, i=0, j=1;
	queue<int> result;
	Node lnode[32];
	while(cin>>n&&n){
		cout << "Case #" << j++ << ":" << endl;
		for(i=0; i<n; i++) cin >> lnode[i].date >> lnode[i].start >> lnode[i].end;
		differ=lnode[0].end-lnode[0].start;
		date=lnode[0].date;
		while(date<10000){
			result.push(date);
			date+=differ;
		}
		for(i=1; i<n; i++){
			len=result.size();
			differ=lnode[i].end-lnode[i].start;
			while(len--){
				date=result.front();
				result.pop();
				if(lnode[i].date==(date-lnode[i].start)%differ+lnode[i].start && date>=lnode[i].start) result.push(date);
			}
		}
		if(result.empty()) cout << "Unknown bugs detected." << endl;
		else cout << "The actual year is " << result.front() << "." << endl;
		while(!result.empty()) result.pop();
		cout << endl; 
	}
	return 0;
}
