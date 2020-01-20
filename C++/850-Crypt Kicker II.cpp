#include<iostream>
using namespace std;
int main()
{
	int a, i, j, k, num, size, size1;
	string sample="the quick brown fox jumps over the lazy dog";
	string str[128],temp;
	int mmap[32];
	bool flag;
	
	cin >> a;
	cin.ignore();
	getline(cin,temp);
	size=sample.size();
	while(a--){
		num=0;
		while(getline(cin,str[num])&&str[num].size()>0) ++num;
		flag=true;
		for(i=0; i<num; i++){
			size1=str[i].size();
			if(size==size1){
				for(j=0; j<size; j++) if(str[i][j]==' '&&sample[j]!=' ') break;
				if(j>=size){
					for(k=0; k<26; k++) mmap[k]=0;
					for(k=0; k<size; k++){
						if(str[i][k]!=' '){
							if(mmap[str[i][k]-97]==0) mmap[str[i][k]-97]=sample[k];
							else if(mmap[str[i][k]-97]!=sample[k]) break; 
						}
					}
					if(k>=size){
						flag=false;
						break;
					}
				}
			}
		}
		if(flag) cout << "No solution." << endl;
		else{
			for(i=0; i<num; i++){
				size1=str[i].size();
				for(j=0; j<size1; j++){
					if(str[i][j]==' ') cout << ' ';
					else cout << (char)mmap[str[i][j]-97];
				}
				cout << endl;
			}
		}
		if(a) cout << endl;
	}
	return 0;
}
