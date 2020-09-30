#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int a, n, i, loc1, loc2, size;
	string str1[256], str2[256];
	vector<int> vect;
	
	cin >> a;
	while(a--){
		cin >> n;
		cin.ignore();
		for(i=0; i<n; i++) getline(cin,str1[i]);
		for(i=0; i<n; i++) getline(cin,str2[i]);
		loc2=loc1=n-1;
		while(loc1>=0){
			if(str1[loc1]==str2[loc2])--loc2;
			--loc1;
		}
		while(loc2>=0){
			cout << str2[loc2--] << endl;
		}
		cout << endl;
	}
	return 0;
}
