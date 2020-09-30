#include<iostream>
using namespace std;
int main()
{
	int a, n=0, y1=0, y2=0, result=0, j=0;
	cin >>a;
	while(a--){
		if(j>0) cout << endl; 
		cin>>n;
		cin >> y1 >> y2;
		result=y1-y2;
		bool state=true;
		for(int i=1; i<n; i++){
			cin >> y1 >> y2;
			if(result!=y1-y2)state=false;
		} 
		if(state) cout << "yes" << endl;
		else cout << "no" << endl;
		j++;
	} 
	return 0;
}
