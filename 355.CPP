#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int state=0, len=0, count=0, i=0;
	long long result=0, mul=0, number=0, num1=0, num2=0;
	char line[128];
	int temp[128];
	while(cin>>num1>>num2>>line){
		len=strlen(line);
		mul=1; result=0; state=1;
		for(i=len-1; i>=0; i--){
			if(line[i]<='9' && line[i]>='0') number=line[i]-48;
			else number=line[i]-55;
			if(number>=num1){
				state=0;
				break;
			}
			result+=mul*number;
			mul*=num1;			
		}
		if(state){
			count=0;
			while(result>0){
				temp[count++]=result%num2;
				result/=num2;
			}
			printf("%s base %ld = ", line, num1);
			if(count==0) printf("0");
			for(i=count-1; i>=0; i--){
				if(temp[i]>=10) printf("%c", temp[i]+55);
				else printf("%d",temp[i]);
			}
			printf(" base %d\n", num2);
		}
		else cout << line << " is an illegal base " << num1 << " number" << endl; 
	}
	return 0;
}
