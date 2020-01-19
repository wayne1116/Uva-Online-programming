#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a=0, i=0, n=0, middle=0, middle1=0, middle2=0, result=0, result1=0, result2=0;
	int num[1024];
	cin >> a;
	while(a--){
		cin >> n;
		for(i=0; i<n; i++) cin>>num[i];
		sort(num,num+n);
		if(middle%2==1){
			middle=num[n/2]; result=0;
			for(i=0; i<n; i++) result+=abs(middle-num[i]);
			cout << result << endl;
		} 
		else{
			middle1=num[n/2]; middle2=num[n/2+1];
			result1=result2=0;
			for(i=0; i<n; i++){
				result1+=abs(middle1-num[i]);
				result2+=abs(middle2-num[i]);
			} 
			cout << ((result1>result2)?(result2):(result1)) << endl;
		}
	}
	return 0;
} 
