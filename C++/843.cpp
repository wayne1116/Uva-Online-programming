#include<iostream>
#include<vector>
using namespace std;
int save1[32], save2[32];
string word[1024];
vector<string> vect[20];

bool back(int next, int count) //回朔法 
{
	int temp1[32],temp2[32];
	int size, i, j, size1;
	string str;
	if(next>=count) return true;
	for(i=0; i<26; i++){          //記錄這個時刻對應的字母 
		temp1[i]=save1[i];
		temp2[i]=save2[i];
	}
	size=word[next].size();
	size1=vect[size].size();
	
	for(i=0; i<size1; i++){
		str=vect[size][i];
		for(j=0; j<size; j++){
			if(save1[str[j]-'a']==-1&&save2[word[next][j]-'a']==-1){
				save1[str[j]-'a']=word[next][j];
				save2[word[next][j]-'a']=str[j];
			}
			else if(save1[str[j]-'a']==-1||save2[word[next][j]-'a']==-1)break;
			else if(save1[str[j]-'a']!=word[next][j]||save2[word[next][j]-'a']!=str[j]) break;
		}
		if(j>=size&&back(next+1,count))return true;
		for(j=0; j<26; j++){
			save1[j]=temp1[j];
			save2[j]=temp2[j];
		}
	} 
	return false;
}
int main()
{
	string str, dict;
	int i, n, j, size, count, begin;
	bool result;
	
	cin >> n;
	for(i=0; i<n; i++){
		cin >> dict;
		size=dict.size();
		vect[size].push_back(dict);
	}
	cin.ignore();
	while(getline(cin,str)){
		str+=' ';
		size=str.size();
		begin=count=0;
		for(i=0; i<26; i++) save1[i]=save2[i]=-1;
		for(i=0; i<size; i++){
			if(str[i]==' '){
				for(j=begin; j<i; j++) word[count]+=str[j];
				begin=i+1;
				++count;
			}
		}
		result=back(0, count);
		if(result){
			for(i=0; i<size-1; i++){
				if(str[i]==' ') cout << ' ';
				else cout << (char)save2[str[i]-'a'];
			}
		}
		else{
			for(i=0; i<size-1; i++){
				if(str[i]==' ') cout << ' ';
				else cout << '*';
			}
		}
		cout << endl;
		for(i=0; i<count; i++) word[i].clear();
	}
	return 0;
}
