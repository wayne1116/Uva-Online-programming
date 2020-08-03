#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i=0;
	char line;
	double upperx[10], uppery[10], lowerx[10], lowery[10];
	double centerx[10], centery[10], radius[10];
	double temp;
	for(int j=0; j<10; j++){
		upperx[j]=uppery[j]=lowerx[j]=lowery[j]=9999.9;
		centerx[j]=centery[j]=9999.9;
	}
	while((cin>> line)){
		if(line=='*'){
			break;
		}
		if(line=='r'){
			cin >> upperx[i] >> uppery[i] >> lowerx[i] >> lowery[i];
			i++;
		}
		else{
			cin >> centerx[i] >> centery[i] >> radius[i];
			i++;
		}
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
			if(upperx[j]!=9999.9){
				if(upperx[j]<x && uppery[j]>y && lowerx[j]>x && lowery[j]<y){
					cout << "Point " << k << " is contained in figure " << j+1 << endl;
					state=false;
				}
			}
			else{
				temp=(x-centerx[j])*(x-centerx[j])+(y-centery[j])*(y-centery[j]);
				temp=sqrt(temp);
				if(temp<radius[j]){
					cout << "Point " << k << " is contained in figure " << j+1 << endl;
					state=false;
				}
			}
		}
		if(state){
			cout << "Point " << k << " is not contained in any figure" << endl;
		}
		k++;
	}
	return 0;
}
