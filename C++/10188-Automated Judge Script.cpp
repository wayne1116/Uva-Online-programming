#include<iostream>
using namespace std;
int main()
{
	int n=0, i=0, j=0, m=0, result=0, index=1;
	string temp1, temp2, line[100], solution[100];
	bool flag=false;
	while(cin>>n && n){
		cin.ignore();
		for(i=0; i<n; i++) getline(cin,solution[i]);
		cin >> m; cin.ignore();
		for(i=0; i<m; i++)getline(cin,line[i]);
		if(n==m){
			result=0;
			for(i=0; i<n; i++){
				if(solution[i]!=line[i]){
					result=1;
					break;
				}
			}
		}
		else result=2;
		if(result!=0){
			temp1.clear(); temp2.clear();
			for(i=0; i<n; i++){
				for(j=0; j<solution[i].size(); j++){
					if(solution[i][j]>='0' && solution[i][j]<='9') temp1+=solution[i][j];
				}
			}
			for(i=0; i<m; i++){
				for(j=0; j<line[i].size(); j++){
					if(line[i][j]>='0' && line[i][j]<='9') temp2+=line[i][j];
				}
			}
			if(temp1==temp2) result=1;
			else result=2;
		}
		cout << "Run #" << index++ << ": " ;
		if(result==0) cout << "Accepted" << endl;
		else if(result==1) cout << "Presentation Error" << endl;
		else cout << "Wrong Answer" << endl;
	}
	return 0;
} 
