#include<iostream>
using namespace std;
int main()
{
	int result[512][128];
	int num1[128], num2[128];
	string str1, str2;
	bool flag1, flag2;
	int i, j, size1, size2, count1, count2, result1;
	
	for(i=0; i<=101; i++) result[0][i]=0;
	result[0][0]=1;
	for(i=0; i<=101; i++) result[1][i]=0;
	result[1][0]=2;
	for(i=2; i<500; i++){
		for(j=0; j<=101; j++)result[i][j]=result[i-1][j]+result[i-2][j];
		for(j=0; j<=101; j++){
			if(result[i][j]>9){
				result[i][j+1]+=1;
				result[i][j]%=10;
			}
		}
	}
	
	while(cin>>str1>>str2){
		if(str1[0]=='0'&&str2[0]=='0') break;
		for(i=0;i<=101; i++) num1[i]=num2[i]=0;
		size1=str1.size();
		for(i=size1-1,j=0; i>=0; i--,j++) num1[j]=str1[i]-48;
		size2=str2.size();
		for(i=size2-1,j=0;i>=0; i--,j++) num2[j]=str2[i]-48;
		
		flag1=flag2=false;
		for(count1=0; count1<500; count1++){
			for(j=101; j>0; j--){
				if(num1[j]!=result[count1][j]) break;
			}
			if(num1[j]<=result[count1][j]) break;
		}
		for(count2=count1; count2<500; count2++){
			for(j=101; j>0; j--){
				if(num2[j]!=result[count2][j]) break;
			}
			if(num2[j]<result[count2][j]) break;
		}
		cout << count2-count1 << endl;
	}
	return 0;
}
