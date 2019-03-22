#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<pair<int,int> > vect[26];
int main()
{
	string str;
	bool flag;
	int a, n, m, i, j, b, k, l;
	int start, start1, len, size, size1, cur1, cur2, next1, next2;
	int dir[8][2]; 
	pair<int,int> temp1, temp;
	cin >> a;
	cin.ignore();
	dir[0][0]=-1; dir[0][1]=-1;
	dir[1][0]=-1; dir[1][1]=0;
	dir[2][0]=-1; dir[2][1]=1;
	dir[3][0]=0; dir[3][1]=1;
	dir[4][0]=1; dir[4][1]=1;
	dir[5][0]=1; dir[5][1]=0;
	dir[6][0]=1; dir[6][1]=-1;
	dir[7][0]=0; dir[7][1]=-1;
	
	while(a--){
		getline(cin,str);
		cin >> n >> m;
		cin.ignore();
		for(i=0; i<26; i++) vect[i].clear();
		for(i=0; i<n; i++){
			getline(cin,str);
			transform(str.begin(),str.end(),str.begin(),::tolower);
			for(j=0; j<m; j++) vect[str[j]-97].push_back(pair<int,int>(i,j));
		}	
		cin >> b;
		cin.ignore();
		while(b--){
			getline(cin,str);
			transform(str.begin(),str.end(),str.begin(),::tolower);
			len=str.size();
			for(i=0; i<8; i++){
				start=str[0]-97;
				size=vect[start].size();
				for(j=0; j<size; j++){
					temp=vect[start][j];
					cur1=temp.first;
					cur2=temp.second;
					flag=true;
					for(k=1; k<len; k++){
						start1=str[k]-97;
						size1=vect[start1].size();
						flag=false;
						for(l=0; l<size1; l++){
							next1=cur1+dir[i][0];
							next2=cur2+dir[i][1];
							temp1=vect[start1][l];
							if(next1==temp1.first && next2==temp1.second){flag=true; break;}
						}
						if(!flag) break;
						else{
							cur1=next1;
							cur2=next2;
						}
					}
					if(flag){
						cout << temp.first+1 << " " << temp.second+1 << endl;
						break;
					}
				}
				if(flag) break;
			}
		}
		if(a) cout << endl;
	}
	return 0;
}
