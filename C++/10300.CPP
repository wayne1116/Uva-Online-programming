#include<iostream>
using namespace std;
int main()
{
	int n=0, m=0;
	long long result=0, a, b, c;
	while(cin>>n){
		for(int i=0; i<n; i++){
			cin >> m;
			result=0;
			for(int j=0; j<m; j++){
				cin >> a >> b >> c;
				result+=a*c;
			}
			cout << result << endl;
		}
	}
	return 0;
}
