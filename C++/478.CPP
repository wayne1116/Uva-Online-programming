#include<iostream>
using namespace std;
struct Node{
	char com;
	double number[6];
};
int main()
{
	Node lnode[16];
	char com;
	int total=0, i=0, j=0, count;
	double x, y, temp, t1, t2, t3, t4, t5, t6, q1, q2,q3,q4,q5,q6;
	bool flag;
	
	while(cin>>com){
		if(com=='*') break;
		else if(com=='r') count=4;
		else if(com=='c') count=3;
		else count=6;
		lnode[total].com=com;
		for(i=0;i<count;i++) cin >> lnode[total].number[i];
		total++; 
	}
	
	j=1;
	while(cin>>x>>y){
		if(x==9999.9 && y==9999.9) break;
		flag=true;
		for(i=0; i<total; i++){
			if(lnode[i].com=='c'){
				temp=(x-lnode[i].number[0])*(x-lnode[i].number[0])+(y-lnode[i].number[1])*(y-lnode[i].number[1]);
				if(temp<lnode[i].number[2]*lnode[i].number[2]){
					flag=false;
					cout << "Point " << j << " is contained in figure " << i+1 << endl;
				}
			}		
			else if(lnode[i].com=='r'){
				if(x>lnode[i].number[0] && x<lnode[i].number[2] && y<lnode[i].number[1] && y>lnode[i].number[3]){
					flag=false;
					cout << "Point " << j << " is contained in figure " << i+1 << endl;
				}
			}
			else{
				t1=lnode[i].number[2]-lnode[i].number[0]; t2=lnode[i].number[3]-lnode[i].number[1];
				t3=lnode[i].number[4]-lnode[i].number[2]; t4=lnode[i].number[5]-lnode[i].number[3];
				t5=lnode[i].number[0]-lnode[i].number[4]; t6=lnode[i].number[1]-lnode[i].number[5];
				
				q1=x-lnode[i].number[0]; q2=y-lnode[i].number[1];
				q3=x-lnode[i].number[2]; q4=y-lnode[i].number[3];
				q5=x-lnode[i].number[4]; q6=y-lnode[i].number[5];
				
				if((t1*q2-t2*q1<0 && t3*q4-t4*q3<0 && t5*q6-t6*q5<0)|| (t1*q2-t2*q1>0 && t3*q4-t4*q3>0 && t5*q6-t6*q5>0)){
					flag=false;
					cout << "Point " << j << " is contained in figure " << i+1 << endl;
				}
			}
		}
		if(flag) cout << "Point " << j << " is not contained in any figure" << endl;
		j++;
	}
	return 0;
}
