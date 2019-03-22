#include<iostream>
using namespace std;
int result[1024][1024];
int main()
{
	int i, a, j;
	for(i=0; i<=1000; i++){
		for(j=0; j<512; j++) result[i][j]=0;
	}
	result[0][0]=1;
	result[1][0]=2;
	result[2][0]=5;
	for(i=3; i<=1000; i++){
		for(j=0; j<511; j++){
			result[i][j]+=result[i-1][j]+result[i-1][j]+result[i-2][j]+result[i-3][j];
			if(result[i][j]>9){
				result[i][j+1]+=result[i][j]/10;
				result[i][j]%=10;
			}
		}
	}
	while(cin>>a){
		for(i=511; i>=0; i--)if(result[a][i]!=0) break;
		for(j=i; j>=0; j--) cout << result[a][j];
		cout << endl;
	}
	return 0;
}
