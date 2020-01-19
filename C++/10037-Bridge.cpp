#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, n, i;
	int temp1, temp2, result, small1, small2;
	int num[1024];
	string str;
	
	cin >> a;
	cin.ignore();
	while(a--){
		getline(cin,str);
		cin >> n;
		for(i=0; i<n; i++)cin >> num[i];
		sort(num,num+n);
		i=n-1;
		small1=num[0];
		small2=num[1];
		result=0;
		while(i>2){
			temp1=small1+small2+num[i]+small2;
			// p[0],p[1]
			// p[0]
			// p[x], p[y]
			// p[1]
			temp2=num[i]+num[i-1]+small1+small1;
			//p[0], p[x]
			//p[0]
			//p[0], p[y]
			//p[0]
			result+=min(temp1,temp2);
			i-=2;
		}
		if(i==0) result=small1;
		else if(i==2) result+=small1+small2+num[2];
		else result+=small2;
		cout << result << endl;
		i=n-1;
		while(i>2){
			temp1=small1+small2+num[i]+small2;
			temp2=num[i]+num[i-1]+small1+small1;
			if(temp1<temp2){
				cout << small1 << " " << small2 <<endl;
				cout << small1 << endl;
				cout << num[i-1] << " " << num[i] << endl;
				cout << small2 << endl;
			}
			else{
				cout << small1 << " " << num[i-1] << endl;
				cout << small1 << endl;
				cout << small1 << " " << num[i] << endl;
				cout << small1 << endl;
			}
			i-=2;
		}
		if(i==0) cout << small1 << endl;
		else if(i==2) {
			cout << small1 << " " << small2 << endl;
			cout << small1 << endl;
			cout << small1 << " " << num[2] << endl;
		}
		else cout << small1 << " " << small2 << endl;
		if(a) cout << endl;
	}
	return 0;
}
