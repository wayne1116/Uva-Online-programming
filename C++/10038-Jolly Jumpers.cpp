#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i=0, n=0, state=0, number[4096], flag[4096], temp=0;
	while(cin>>n){
		for(i=0; i<n; i++){
			cin>>number[i];
			flag[i]=0;
		}
		state=1;
		for(i=1; i<n; i++){
			temp=abs(number[i]-number[i-1]);
			if(temp>n-1||flag[temp]){
				state=0;
				break;
			}
			else flag[temp]=1;
		}
		if(state)cout << "Jolly" << endl;
		else cout << "Not jolly" << endl; 
	}
	return 0;
}
