#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main()
{
	char line[1024];
	int number=0, i=0, start=0, count=0, target=0, j=0;
	queue<pair<int,char> > qu[13];
	pair<int,char> temp;
	while(cin>>line){
		if(line[0]=='#') break;
		if(line[0]>='2' && line[0]<='9') number=line[0]-48;
		else if(line[0]=='A') number=1;
		else if(line[0]=='T') number=10;
		else if(line[0]=='J') number=11;
		else if(line[0]=='Q') number=12;
		else number=13;
		qu[0].push(pair<int,char>(number,line[1]));
		for(i=51; i>=1; i--){
			cin >> line;
			if(line[0]>='2' && line[0]<='9') number=line[0]-48;
			else if(line[0]=='A') number=1;
			else if(line[0]=='T') number=10;
			else if(line[0]=='J') number=11;
			else if(line[0]=='Q') number=12;
			else number=13;
			qu[i%13].push(pair<int,char>(number,line[1]));
		}
		start=0; count=0;
		while(1){
			if(qu[start].empty()){
				printf("%02d,",count);
				if(temp.first>=2 && temp.first<=9) cout << temp.first;
				else if(temp.first==1) cout << "A";
				else if(temp.first==10) cout << "T";
				else if(temp.first==11) cout << "J";
				else if(temp.first==12) cout << "Q";
				else cout << "K";
				cout << temp.second << endl;
				break;
			}
			temp=qu[start].front();
			qu[start].pop();
			target=temp.first%13;
			count++;
			start=target;
		}
		for(i=0; i<13; i++){
			while(!qu[i].empty()) qu[i].pop();
		}
	}
	return 0;
}
