#include<iostream>
using namespace std;
int main()
{
	int a=0, n=0, m=0, i=0, j=0, k=0, index, count=0;
	char com[128][8];
	int weight[128], weight1=0, weight2=0;
	int num[128][128];
	bool flag, state;
	cin >> a;
	while(a--){
		if(count>0) cout << endl;
		cin>> n >> m;
		for(i=0; i<m; i++){
			cin >> num[i][0];
			for(j=1; j<=2*num[i][0]; j++) cin >> num[i][j];
			cin >> com[i]; 
		}
		flag=false; state=true;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++) weight[j]=0;
			weight[i]=1;
			for(j=0; j<m; j++){
				weight1=weight2=0;
				for(k=0; k<num[j][0]; k++) {
					weight1+=weight[num[j][k+1]-1];
					weight2+=weight[num[j][num[j][0]+k+1]-1];
				}
				if(com[j][0]=='<'&&weight1<weight2);
				else if(com[j][0]=='='&&weight1==weight2);
				else if(com[j][0]=='>'&&weight1>weight2);
				else break;
			}
			if(j>=m){
				if(flag){
					state=flag=false;
					break;
				}
				index=i+1;
				flag=true;
			}
		}
		if(state){
			for(i=0; i<n; i++){
				for(j=0; j<n; j++) weight[j]=1;
				weight[i]=0;
				for(j=0; j<m; j++){
					weight1=weight2=0;
					for(k=0; k<num[j][0]; k++) {
						weight1+=weight[num[j][k+1]-1];
						weight2+=weight[num[j][num[j][0]+k+1]-1];
					}
					if(com[j][0]=='<'&&weight1<weight2);
					else if(com[j][0]=='='&&weight1==weight2);
					else if(com[j][0]=='>'&&weight1>weight2);
					else break;
				}
				if(j>=m){
					if(flag && index!=i+1){
						flag=false;
						break;
					}
					index=i+1;
					flag=true;
				}
			}
		} 
		if(flag) cout << index << endl;
		else cout << 0 << endl;
		count++;
	}
	return 0;
}
