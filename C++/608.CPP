#include<iostream>
#include<string>
using namespace std;
int flag[16];
string line1[3], line2[3], com[3];
bool solv()
{
	int i=0, j=0, temp1=0, temp2=0, len=0;
	for(i=0; i<3; i++){
		len=line1[i].size();
		temp1=temp2=0;
		for(j=0; j<len; j++){
			temp1+=flag[line1[i][j]-65];
			temp2+=flag[line2[i][j]-65];
		}
		if(!(com[i]=="even" && temp1==temp2 || com[i]=="up" && temp1>temp2 || com[i]=="down" && temp1<temp2)) return false;
	}
	return true;
}
int main()
{
	int i=0, j=0, a=0;
	string result1, result2;
	bool result;
	cin >> a;
	while(a--){
		for(i=0; i<3; i++) cin >> line1[i] >> line2[i] >> com[i];
		for(i=0; i<12; i++){
			for(j=0; j<12; j++) flag[j]=1;
			flag[i]=0;
			result=solv();
			if(result){
				result1=i+65;
				result2="light";
				break;
			}
		}
		for(i=0; i<12; i++){
			for(j=0; j<12; j++) flag[j]=0;
			flag[i]=1;
			result=solv();
			if(result){
				result1=i+65;
				result2="heavy";
				break;
			}
		}
		cout << result1 << " is the counterfeit coin and it is " << result2 << "." << endl;
	}
	return 0;
} 
