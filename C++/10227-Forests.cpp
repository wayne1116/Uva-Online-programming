#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	int a=0, i=0, j=0, count=0, persion, tree, k=0, n, m;
	bool state[128], result[128][128];
	char line[128], *ptr;
	cin >> a;
	cin.ignore(); cin.ignore();
	while(a--){
		cin >> n >> m; cin.ignore();
		for(i=0; i<n; i++){
			for(j=0; j<m; j++) result[i][j]=false;
			state[i]=true; 
		} 
		while(cin.getline(line,128)){
			if(strlen(line)==0) break;
			persion=atoi(line); ptr=line;
			while(*ptr){
				if(*ptr==' '){
					tree=atoi(ptr);
					break;
				}
				ptr++;
			}
			result[persion-1][tree-1]=true;
			state[persion-1]=true;
		}
		count=0;
		if(n!=0 && m==0 )count=1;
		for(i=0; i<n; i++){
			if(state[i]){
				state[i]=false;
				++count;
				for(j=i+1; j<n; j++){
					if(state[j]){
						for(k=0; k<m; k++){
							if(result[i][k]!=result[j][k]) break;
						}
						if(k>=m) state[j]=false;
					}
				}
			}
		}
		cout << count << endl;
		if(a) cout << endl;
	}
	return 0;
}
