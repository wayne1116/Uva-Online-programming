#include<iostream>
using namespace std;
int main()
{
	string line, flag, line1;
	int i=0, pow=0, result=0;
	while(cin>>line && line!="~"){
		if(line=="#"){
			pow=1; result=0;
			for(i=line1.size()-1; i>=0; i--){
				if(line1[i]=='1') result+=pow;
				pow*=2;
			}
			cout << result << endl;
			line1.clear();
		}
		else if(line.size()==1)
			flag="1";
		else if(line.size()==2)
			flag="0";
		else{
			for(i=0; i<line.size()-2; i++)
				line1+=flag;
		}
	}
	return 0;
}
