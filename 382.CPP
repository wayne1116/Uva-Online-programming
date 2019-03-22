#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int flag[60001]={2,2};
	int i=0, j=0, limit=0,sum=0, number=0;
	for(i=2; i<=60000; i++){
		limit=sqrt(i);
		sum=1;
		for(j=2; j<=limit; j++){
			if(i%j==0){
				if(i/j!=j) sum+=(i/j)+j;
				else sum+=j;
			}
		}
		if(sum==i) flag[i]=1;
		else if(sum<i) flag[i]=2;
		else flag[i]=3;
	}
	cout << "PERFECTION OUTPUT" << endl;
	while(cin>>number && number){
		cout << setw(5) << number<< "  ";
		if(flag[number]==1) cout << "PERFECT" << endl;
		else if(flag[number]==2) cout << "DEFICIENT"<<endl;
		else cout <<"ABUNDANT"<<endl;  
	} 
	cout <<"END OF OUTPUT"<<endl; 
	return 0;
}
