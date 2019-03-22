#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n=0, number1=0, number2=0, result=0, temp1[13], temp2[13], i=0;
	char oper;
	cin >> n;
	while(n--){
		cin >> hex >> number1;
		cin >> oper;
		cin >> hex >> number2;
		if(oper=='+') result=number1+number2;
		else result=number1-number2;
		for(i=0; i<13; i++) temp1[i]=temp2[i]=0;
		i=0;
		while(number1>0){
			temp1[i++]=number1%2;
			number1/=2;
		}
		i=0;
		while(number2>0){
			temp2[i++]=number2%2;
			number2/=2;
		}
		for(i=12; i>=0; i--) cout << temp1[i];
		cout << " " << oper << " ";
		for(i=12; i>=0; i--) cout << temp2[i];
		cout << " = " << result << endl;
	}
	return 0;
}
