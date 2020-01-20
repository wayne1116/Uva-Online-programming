#include<iostream>
using namespace std;
int main()
{
	int n, m, i, j;
	long long black[16][16], white[16][16], rowb[16], roww[16];
	long long sum;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		else if(n==1&&m==1){
			cout << 1 << endl;
			continue; 
		}
		else if(m>2*n-2){
			cout << 0 << endl;
			continue;
		}
		for(i=0; i<16; i++){
			for(j=0; j<16; j++) black[i][j]=white[i][j]=0;
		}
		for(i=0; i<=n; i++) black[i][0]=white[i][0]=1;
		rowb[0]=roww[0]=0;
		for(i=1; i<=8; i++){
			if(i&1) rowb[i]=i;
			else rowb[i]=rowb[i-1];
		}
		for(i=1; i<=8; i++){
			if(i&1) roww[i]=i+1;
			else roww[i]=roww[i-1];
		}
		for(i=1; i<=n; i++){
			for(j=1; j<=rowb[i]; j++){
				black[i][j]=black[i-1][j]+black[i-1][j-1]*(rowb[i]-j+1);
			}
		} 
		for(i=1; i<=n; i++){
			for(j=1; j<=roww[i]; j++){
				white[i][j]=white[i-1][j]+white[i-1][j-1]*(roww[i]-j+1);
			}
		}
		sum=0;
		for(i=0; i<=m; i++) sum+=black[n][i]*white[n-1][m-i];
		cout << sum << endl;
	} 
	return 0;
}
