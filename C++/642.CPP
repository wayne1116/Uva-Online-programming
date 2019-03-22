#include<iostream>
#include<algorithm> 
using namespace std;
struct Node{
	string line;
	int number[26];
};
bool cmp(Node &x, Node &y)
{
	return y.line>x.line;
}
int main()
{
	int i=0, j=0, k=0, sum=0, number[26];
	string temp;
	bool state;
	Node lnode[128];
	while(cin>>temp){
		if(temp=="XXXXXX") break;
		lnode[i].line=temp; sum=0;
		for(j=0; j<26; j++) lnode[i].number[j]=0;
		for(j=0; j<temp.size(); j++) lnode[i].number[temp[j]-97]++;
		i++;
	}
	sort(lnode,lnode+i,cmp);
	while(cin>>temp){
		if(temp=="XXXXXX") break;
		for(j=0; j<26; j++) number[j]=0;
		for(j=0; j<temp.size(); j++) number[temp[j]-97]++;
		state=true;
		for(j=0; j<i; j++){
			for(k=0; k<26; k++){
				if(lnode[j].number[k]!=number[k]) break;
			}
			if(k>=26){
				cout << lnode[j].line << endl;
				state=false;
			}
		} 
		if(state) cout << "NOT A VALID WORD" << endl; 
		cout << "******" << endl;
	}
	return 0;
}
