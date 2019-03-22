#include<iostream>
#include<algorithm>
using namespace std;
int cal(char flow, char num)
{
	int result=0;
	if(flow=='C') result=-1;
	else if(flow=='D') result=12;
	else if(flow=='S') result=25;
	else result=38;
	if(num>='2' && num<='9') result+=num-49;
	else if(num=='T') result+=9;
	else if(num=='J') result+=10;
	else if(num=='Q') result+=11;
	else if(num=='K') result+=12;
	else result+=13;
	return result;
}
int main()
{
	char line[32], poke1[64], poke2[64], dir[8]="SWNE", flow[8]="CDSH", number[16]="23456789TJQKA";
	int start, num[4][64], i=0, j=0, count=0;
	while(cin>>line && line[0]!='#'){
		cin >> poke1 >> poke2;
		if(line[0]=='N') start=3;
		else if(line[0]=='E') start=0;
		else if(line[0]=='S') start=1;
		else start=2;
		count=0; j=0;
		for(i=0; i<52; i+=2){
			if(count%4==0 && count!=0) j++;
			num[start][j]=cal(poke1[i],poke1[i+1]);
			start=(start+1)%4;
			count++;
		}
		for(i=0; i<52; i+=2){
			if(count%4==0) j++;
			num[start][j]=cal(poke2[i],poke2[i+1]);
			start=(start+1)%4;
			count++;
		}
		for(i=0; i<4; i++) sort(num[i],num[i]+13);
		for(i=0; i<4; i++){
			cout << dir[i] << ":";
			for(j=0; j<13; j++) cout << " " << flow[num[i][j]/13] << number[num[i][j]%13];
			cout << endl;
		}
	}
	return 0;
}
