#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<cctype>
using namespace std;
map<string,int> mmap1; 
struct Node{
	string name;
	int win, lose, tie;
	int wpoint, lpoint;
	int index, point, play;
};
bool cmp(const struct Node &a, const struct Node &b)
{
	if (a.point != b.point) return a.point > b.point; //得分高的優先
  	if (a.win != b.win) return a.win > b.win;//勝場數高的優先
  	if (a.wpoint-a.lpoint != b.wpoint-b.lpoint)  return a.wpoint-a.lpoint > b.wpoint-b.lpoint;//進球數差高的優先
  	if (a.wpoint != b.wpoint) return a.wpoint > b.wpoint; //進球數高的優先
  	if (a.play != b.play) return a.play < b.play;//比賽場數低的優先
  	for (int i = 0; i < min(a.name.length(), b.name.length()); i++)  {  // Case-insensitive lexicographic order
    	if (isalpha(a.name[i]) && isalpha(b.name[i]))  {  //若a.name[i]與b.name[i]都是大小寫英文字母
      		if (toupper(a.name[i]) != toupper(b.name[i])) return toupper(a.name.at(i)) < toupper(b.name.at(i));  
     	}	  
		else  return a.name[i] < b.name[i];  //不同時為英文字母
  	}  
  	return a.name.length() < b.name.length();  //若兩字串前面都相同，就比較字串長度，短的優先
}

int main()
{
	int a, i, j, n, b, size, temp1, temp2;
	int goal1, goal2;
	bool flag;
	string str, line, team1, team2, title;
	struct Node lnode[64];
	
	cin >> a;
	cin.ignore();
	while(a--){
		getline(cin,title);
		cin >> n;
		cin.ignore();
		mmap1.clear();
		for(i=0; i<n; i++){
			getline(cin,str);
			mmap1[str]=i;
			lnode[i].name.clear();
			for(j=0; j<str.size(); j++) lnode[i].name+=str[j];
			lnode[i].index=i;
			lnode[i].wpoint=lnode[i].lpoint=0;
			lnode[i].win=lnode[i].lose=lnode[i].tie=0;
			lnode[i].point=lnode[i].play=0;
		}
		cin >> b;
		cin.ignore();
		while(b--){
			getline(cin,line);
			size=line.size();
			goal1=0; team1.clear(); flag=false;
			for(i=0; i<size; i++){
				if(line[i]>='0'&&line[i]<='9'&&flag)goal1=goal1*10+line[i]-48;
				else if(line[i]=='@') break;
				else if(line[i]=='#'){
					flag=true;
					for(j=0; j<i; j++) team1+=line[j];
				}
			}
			goal2=0; team2.clear();
			for(j=i; j<size; j++){
				if(line[j]>='0'&&line[j]<='9') goal2=goal2*10+line[j]-48;
				else if(line[j]=='#') break;
			}
			++j;
			while(j<size)team2+=line[j++];
			temp1=mmap1[team1]; temp2=mmap1[team2];
			lnode[temp1].wpoint+=goal1;
			lnode[temp1].lpoint+=goal2;
			lnode[temp2].wpoint+=goal2;
			lnode[temp2].lpoint+=goal1;
			lnode[temp1].play++;
			lnode[temp2].play++;
			if(goal1>goal2){
				lnode[temp1].win++;
				lnode[temp2].lose++;
			}
			else if(goal1<goal2){
				lnode[temp1].lose++;
				lnode[temp2].win++;
			}
			else{
				lnode[temp1].tie++;
				lnode[temp2].tie++;
			}
			lnode[temp1].point=lnode[temp1].win*3+lnode[temp1].tie;
			lnode[temp2].point=lnode[temp2].win*3+lnode[temp2].tie;
		}
		sort(lnode,lnode+n,cmp);
		cout << title << endl;
		for(i=0; i<n; i++){
			cout << i+1 << ") " << lnode[i].name << " " << lnode[i].point << "p, ";
			cout << lnode[i].play << "g (" << lnode[i].win << "-" << lnode[i].tie << "-" << lnode[i].lose << "), ";
			cout << lnode[i].wpoint-lnode[i].lpoint << "gd (" << lnode[i].wpoint << "-" << lnode[i].lpoint << ")" << endl; 
		}
		if(a) cout << endl;
	}
	return 0;
}
