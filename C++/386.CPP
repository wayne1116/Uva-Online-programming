#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i, j, k, l=0;
	int temp;
	
	for(i=2; i<=200; i++){
		for(j=2; j<=i; j++){
			for(k=j; k<=i; k++){
				for(l=k; l<=i; l++){
					temp=i*i*i-j*j*j-k*k*k-l*l*l;
					if(temp<0) break;
					if(temp==0) cout << "Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
				}
			}
		} 
	}
	return 0;
}
