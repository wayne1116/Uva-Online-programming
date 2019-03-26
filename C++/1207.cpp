#include<iostream>
using namespace std;
int result[1024][1024];
inline int Min(int x, int y)
{
	return x>y?y:x;
}
int main()
{
	int n, m, i, j;
	char line1[1024], line2[1024];
	
	while(cin>>n>>line1>>m>>line2){
		for(i=0; i<=n; i++) result[i][0]=i;
		for(i=0; i<=m; i++) result[0][i]=i;
		result[0][0]=0;
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				if(line1[i-1]==line2[j-1]) result[i][j]=result[i-1][j-1];
				else result[i][j]=Min(result[i-1][j-1],Min(result[i-1][j],result[i][j-1]))+1;
			}
		}
		cout << result[n][m] << endl;
	}
	return 0;
}
