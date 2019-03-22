#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a=0, n=0, i, j, aver, sum;
	int num[1024], result[100000];
	cin >> a;
	while(a--){
		cin >> n;
		sum=0;
		for(i=0; i<n; i++){
			cin >> num[i];
			sum+=num[i];
		}
		aver=sum/2; //越接近平均數 
		for(i=0; i<=aver; i++) result[i]=0;
		for(i=0; i<n; i++){
			for(j=aver; j>=num[i]; j--){
				result[j]=max(result[j],result[j-num[i]]+num[i]); 
			}
		}
		cout << (sum-result[aver])-result[aver] << endl;
	} 
	return 0;
}
