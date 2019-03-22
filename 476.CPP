#include<iostream>
using namespace std;
int main()
{
	int i=0;
	string line;
	float upperx[10], uppery[10], lowerx[10], lowery[10];
	while((cin>> line)){
		if(line[0]=='*'){
			break;
		}
		cin >> upperx[i] >> uppery[i] >> lowerx[i] >> lowery[i];
		i++;
	}
	int k=1;
	double x=0;
	double y=0;
	while((cin >> x >> y)){
		if(x==9999.90000 && y==9999.90000){
			break;
		}
		int state=true;
		for(int j=0; j<i; j++){
			if(upperx[j]<x && uppery[j]>y && lowerx[j]>x && lowery[j]<y){
				cout << "Point " << k << " is contained in figure " << j+1 << endl;
				state=false;
			}
		}
		if(state){
			cout << "Point " << k << " is not contained in any figure" << endl;
		}
		k++;
	}
	return 0;
}
