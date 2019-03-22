#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int i=0, count=0;
	long long number[100000][2], temp;
	while(cin>>temp){
		for(i=0; i<count; i++)
			if(number[i][0]==temp){
				number[i][1]++;
				break;
			}
		if(i>=count){
			number[count][0]=temp;
			number[count][1]=1;
			count++;
		}
	}
	for(i=0; i<count; i++) cout << number[i][0] << " " << number[i][1]<< endl;
	return 0;
}
