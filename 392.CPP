#include<iostream>
using namespace std;
int main()
{
	int coef[16];
	while(cin>>coef[8]){
		for(int i=7; i>=0; i--) cin >>coef[i];
		bool flag=false;
		for(int i=8; i>0; i--){
			if(coef[i]!=0){
				if(flag){
					if(coef[i]>0) cout <<" + ";
					else cout <<" - ";
					if(coef[i]<0) coef[i]=-coef[i];
					if(coef[i]>1) cout <<coef[i]; 
				}
				else{
					if(coef[i]!=1 && coef[i]!=-1) cout<<coef[i];
					else if(coef[i]==-1) cout<<"-";
				}
				if(i>1) cout<<"x^"<<i;
				else cout << "x";
				flag=true;
			}
		} 
		if(coef[0]!=0){
			if(flag){
				if(coef[0]>0) cout <<" + ";
				else cout << " - ";
				if(coef[0]<0) coef[0]=-coef[0];
				cout << coef[0]; 
			}
			else cout <<coef[0];
			flag=true; 
		}
		if(!flag) cout << 0;
		cout <<endl; 
	}
	return 0;
}
