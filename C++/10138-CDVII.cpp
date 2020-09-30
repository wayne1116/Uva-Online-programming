#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Node{
	string name;
	int toll;
	int day;
	bool sel;
	int location;
};
bool cmp(const struct Node &x, const struct Node &y)
{
	//string line1, line2;
	if(x.name==y.name) return y.day>x.day; 
	//transform(x.name.begin(),x.name.end(),line1.begin(),::tolower);
	//transform(y.name.begin(),y.name.end(),line2.begin(),::tolower);
	//cout << line1 << line2 << endl; 
	return y.name>x.name;
}
int main()
{
	int a, i, j, count, size, location, day, hour, minu;
	string str, name;
	struct Node lnode[1024];
	int toll[32];
	double totalcost, cost, distance, toll1;
	bool flag;
	
	cin >> a;
	cin.ignore();
	while(a--){
		for(i=0; i<24; i++) cin >> toll[i];
		cin.ignore();
		count=0;
		while(getline(cin,str)&&str.size()>0){
			size=str.size();
			for(i=0; i<size; i++){
				if(str[i]==' ') break;
			}
			lnode[count].name.clear();
			for(j=0; j<i; j++) lnode[count].name+=str[j];
			++i;
			day=(10*(str[i]-48)+(str[i+1]-48))*30;
			day=(day+(str[i+3]-48)*10+(str[i+4]-48))*24;
			hour=10*(str[i+6]-48)+str[i+7]-48;
			minu=10*(str[i+9]-48)+str[i+10]-48;
			i=i+12;
			lnode[count].toll=toll[hour];
			lnode[count].day=(day+hour)*60+minu;
			if(str[i+1]=='n') lnode[count].sel=true;
			else lnode[count].sel=false;
			while(i<size){
				if(str[i]>='0'&&str[i]<='9')break;
				++i;
			} 
			location=0;
			while(i<size){
				location=location*10+str[i]-48;
				++i;
			} 
		
			lnode[count].location=location;
			++count;
		}
		sort(lnode,lnode+count,cmp);
		i=0;
		while(i<count){
			name=lnode[i].name;
			totalcost=0;
			flag=false;
			for(j=i; j<count; j++){
				if(name!=lnode[j].name) break;
				else if(lnode[j].sel){
					toll1=lnode[j].toll;
					location=lnode[j].location;
					flag=true;
				}
				else if(flag){
					distance=abs(location-lnode[j].location);
					cost=distance*toll1/100;
					totalcost+=cost+1;
					flag=false;
				}
			}
			if(totalcost!=0) cout << fixed << setprecision(2) << name << " $" << totalcost+2 << endl;
			i=j;
		}
		if(a) cout << endl;
	}
	return 0;
}
