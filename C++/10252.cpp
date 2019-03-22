#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string str1, str2;
	int len1, len2, i, j, size;
	int count1[32], count2[32];
	while(getline(cin,str1)){
		getline(cin,str2);
		for(i=0; i<26; i++) count1[i]=count2[i]=0;
		len1=str1.size();
		for(i=0; i<len1; i++) ++count1[str1[i]-97];
		len2=str2.size();
		for(i=0; i<len2; i++) ++count2[str2[i]-97];
		for(i=0; i<26; i++){
			size=min(count1[i],count2[i]);
			for(j=0; j<size; j++) cout << (char)(i+97);
		}
		cout << endl;
	}
	return 0;
}
