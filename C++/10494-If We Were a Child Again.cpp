#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	char line1[100000], line2[64], com[8], temp[64], temp1[64];
	int len1=0, len2=0, i=0, j=0, k=0, l=0, count=0, div[100000];
	long long num1=0, num2=0;
	 
	while(cin>>line1>>com>>line2){
		len1=strlen(line1);
		len2=strlen(line2);
		num2=atoi(line2);
		num1=0;
		if(len1<=len2){
			for(i=0; i<len1; i++) num1=num1*10+line1[i]-48;
			if(com[0]=='/') cout << num1/num2 << endl;
			else cout << num1%num2 << endl;
		}
		else{
			num1=0;
			for(i=0; i<len2; i++) num1=num1*10+line1[i]-48;
			count=0;
			while(i<len1){
				div[count++]=num1/num2;
				num1=num1%num2;
				num1=num1*10+line1[i]-48;
				++i;
			}
			if(com[0]=='%') cout << num1%num2 << endl;
			else{
				div[count++]=num1/num2;
				for(i=0; i<count; i++) if(div[i]!=0) break;
				for(j=i; j<count; j++) cout << div[j];
				cout << endl;
			}
		}
	}
	return 0;
}

