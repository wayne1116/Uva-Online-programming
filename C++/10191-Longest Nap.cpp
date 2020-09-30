#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int start;
	int end;
};
bool cmp(const struct Node &x, const struct Node &y)
{
	return y.start>x.start;
}
int main()
{
	int n, i, hour, end, start, Max, result, minu, end1;
	string str;
	struct Node lnode[128];
	int day=0;
	
	while(cin>>n){
		cin.ignore();
		for(i=0; i<n; i++){
			getline(cin,str);
			hour=(str[0]-48)*10+(str[1]-48);
			minu=(str[3]-48)*10+(str[4]-48);
			start=hour*60+minu;
			
			hour=(str[6]-48)*10+(str[7]-48);
			minu=(str[9]-48)*10+(str[10]-48);
			end=hour*60+minu;
			lnode[i].start=start;
			lnode[i].end=end;
		}
		lnode[i].start=lnode[i].end=18*60;
		sort(lnode,lnode+n,cmp);
		Max=0;
		end1=result=10*60;
		for(i=0; i<=n; i++){
			start=lnode[i].start;
			end=lnode[i].end;
			if(end1<start){
				if(Max<start-end1){
					Max=start-end1;
					result=end1;
				}
				end1=end;
			}
			else if(end1>=start&&end1<=end) end1=end;
		}
		cout << "Day #" << ++day << ": the longest nap starts at " << result/60 << ":";
		if(result%60<10) cout << "0";
		cout << result%60 << " and will last for ";
		if(Max>=60){
			cout << Max/60 << " hours ";
			if(Max%60==0) cout << "and 0 minutes." << endl;
			else cout << "and " << Max%60 << " minutes." << endl;
		}
		else cout << Max%60 << " minutes." << endl;
		 
	}
	return 0;
}
