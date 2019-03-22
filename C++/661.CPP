#include<iostream>
using namespace std;
int main()
{
	bool state[32], flag;
	int current[32], n, m, c, a, sum, max, i, j=1;
	while(cin>>n>>m>>c){
		if(n+m+c==0) break;
		//if(j>1) cout << endl;
		cout << "Sequence " << j++ << endl; 
		for(i=0; i<n; i++){
			cin >> current[i];
			state[i]=false;
		}
		flag=true; sum=max=0;
		for(i=0; i<m; i++){
			cin >> a;
			if(flag==false) continue;
			else if(!state[a-1]){
				if(sum+current[a-1]>c) flag=false;
				else sum+=current[a-1];
				if(max<sum) max=sum;
				state[a-1]=true;
			}
			else{
				state[a-1]=false;
				sum-=current[a-1];
			}
		}
		if(flag){
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was "<< max << " amperes." << endl;
		}
		else cout << "Fuse was blown." << endl;
		cout << endl;
	}
	return 0;
}
