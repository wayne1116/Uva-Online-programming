#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, n, count, temp, i;
	int top[64];
	cin >> a;
	while(a--){
		cin >> n;
		for(i=0; i<n; i++) top[i]=0;
		count=1;
		while(true){
			for(i=0; i<n; i++){
				temp=sqrt(top[i]+count);
				if(temp*temp==top[i]+count||top[i]==0){
					top[i]=count;
					break;
				}
			}
			if(i>=n) break;
			++count;
		}
		cout << count-1 << endl;
	}
	return 0;
}
