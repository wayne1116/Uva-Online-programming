#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a=0, i=0, j=0, temp=0, row=0, col=0;
	int path[128][128], result[128][128];
	char line[1024], *ptr;
	cin >> a;
	while(a--){ 
		cin >> row >> col;
		for(i=0; i<row; i++){
			for(j=0; j<col; j++) path[i][j]=0;
		}
		getchar();
		for(i=0; i<row; i++){
			cin.getline(line,1024);
			ptr=line;
			while(*ptr){
				if(*ptr==' '){
					ptr++;
					temp=atoi(ptr);
					path[i][temp-1]=-1;
				}
				ptr++;
			}
		}
		for(i=0; i<row; i++){
			if(path[i][0]==0) result[i][0]=1;
			else break;
		}
		for(j=i; j<row; j++) result[j][0]=0;
		for(i=0; i<col; i++){
			if(path[0][i]==0) result[0][i]=1;
			else break;
		}
		for(j=i; j<col; j++) result[0][j]=0;
		for(i=1; i<row; i++){
			for(j=1; j<col; j++){
				if(path[i][j]==0) result[i][j]=result[i-1][j]+result[i][j-1];
				else result[i][j]=0;
			}
		}
		cout << result[row-1][col-1] << endl;
		if(a) cout << endl; 
	}
	return 0;
}
