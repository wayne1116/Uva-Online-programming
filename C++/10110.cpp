#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long a, i, count, limit;
	while(cin>>a&&a){                   //�]���u���_�ƭӦ]�Ƥ~�|�ϿO�w�G�A�ӯಣ�ͩ_�ƭӦ]�ƥu����������� 
		limit=sqrt(a);
		if(limit*limit==a) cout << "yes";
		else cout << "no";
		cout << endl;
	}
	return 0;
}
