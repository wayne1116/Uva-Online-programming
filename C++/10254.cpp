#include<iostream>
using namespace std;
int result[10001][64];
int main()
{
	int i, a;
	int mul[64], count, j, k;
	for(i=0; i<64; i++) mul[i]=0;
	for(i=0; i<=10000; i++){
		for(j=0; j<64; j++) result[i][j]=0;
	}
	result[0][0]=0;
	result[1][0]=1;
	i=2;
	mul[0]=2;
	count=2;
	while(i<=10000){
		for(j=0; j<count; j++) {
			for(k=0; k<63; k++){
				result[i][k]+=result[i-1][k]+mul[k];
				if(result[i][k]>9){
					++result[i][k+1];
					result[i][k]%=10;
				}
				
			}
			++i;
		}
		++count;
		for(j=0; j<64; j++) mul[j]*=2;
		for(j=0; j<63; j++){
			if(mul[j]>9){
				++mul[j+1];
				mul[j]%=10;
			}
		}
	}
	while(cin>>a){
		for(i=63; i>0; i--)if(result[a][i]!=0) break;
		for(j=i; j>=0; j--) cout << result[a][j];
		cout << endl;
	}
	return 0;
}
