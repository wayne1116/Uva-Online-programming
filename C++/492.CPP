#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool vowel[128];
bool isletter(char c)
{
	return (c>='A' && c<='Z')||(c>='a'&&c<='z');
}
int main()
{
	string line;
	char alpha, alpha1;
	bool flag;
	int i=0, len=0;
	for(i=0; i<128; i++) vowel[i]=false;
	vowel['A']=vowel['E']=vowel['I']=vowel['O']=vowel['U']=true;
	vowel['a']=vowel['e']=vowel['i']=vowel['o']=vowel['u']=true;
	while(getline(cin,line)){
		len=line.size();
		for(i=0; i<len; i++){
			if(isletter(line[i])){
				alpha=line[i];
				if(!vowel[alpha]) i++;
				for(;isletter(line[i])&&i<len;i++) cout << line[i];
				if(!vowel[alpha]) cout << alpha;
				cout << "ay";
				i--;
			}
			else cout << line[i];
		}
		cout << endl;
	}
	return 0;
}
