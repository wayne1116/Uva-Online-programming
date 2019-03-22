#include<iostream>
using namespace std;
int main()
{
	int n=0, i=0, j=0, index1=0, index2=0, result=0;
	int matrix[128][128], row[128], col[128];
	while(cin>>n && n){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				cin >> matrix[i][j];
			} 
		}
		result=0; index1=index2=-1;
		for(i=0; i<n; i++){
			row[i]=0; col[i]=0;
			for(j=0; j<n; j++) {
				row[i]+=matrix[i][j];
				col[i]+=matrix[j][i];
			}
			if(row[i]%2!=0){
				index1=i;
				result++;
			}
			if(col[i]%2!=0){
				result++;
				index2=i;
			}
		}
		if(result==0) cout << "OK" << endl;
		else if(result>2 || index1==-1 || index2==-1) cout << "Corrupt" << endl;
		else{
			cout << "Change bit (" << index1+1 << "," << index2+1<<")"<<endl;
		}
	}
	return 0;
}
