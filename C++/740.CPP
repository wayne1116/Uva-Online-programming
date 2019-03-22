#include<iostream>
using namespace std;
int main()
{
	string role[2], line;
	int i=0, j=0, result=0, count=0, flag=0;
	int power[5]={16,8,4,2,1}, temp[32];
	
	getline(cin,role[0]);
	getline(cin,role[1]);
	count=0;
	for(i=0; i<role[0].size(); i++){
		if(role[0][i]==' ') temp[i]=count++;
	}
	while(cin>>line){
		i=flag=0; 
		while(i<line.size()){
			result=0;
			for(j=0; j<5; j++) result=result+(line[j+i]-48)*power[j];
			if(role[flag][result]==' '){
				if(temp[result]==0) cout << ' ';
				else if(temp[result]==1) flag=0;
				else flag=1;
			}
			else cout << role[flag][result];
			i+=5;
		}
		cout << endl;
	}
	return 0;
}
