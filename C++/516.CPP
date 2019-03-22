#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	char line[1024], *ptr;
	int num=0, num1=0, mul=0, i=0, result=0, j=0, count=0, limit=0, temp1=0, k=0;
	int temp[4096];
	bool flag;
	
	for(i=32767; i>=2; i--){
		limit=sqrt(i);
		for(j=2; j<=limit; j++){
			if(i%j==0) break;
		}
		if(j>limit) temp[count++]=i;
	}
	while(cin.getline(line,1024)){
		if(line[0]=='0') break;
		ptr=line;
		num=atoi(ptr); flag=true; result=1;
		while(*ptr){
			if(*ptr==' '){
				ptr++;
				num1=atoi(ptr);
				if(flag){
					flag=false;
					mul=1;
					for(i=0; i<num1; i++) mul*=num;
					result*=mul;
				}
				else{
					flag=true;
					num=num1;
				}
			}
			ptr++;
		}
		result=result-1; k=0;
		for(i=0; i<count; i++){
			if(result%temp[i]==0){
				temp1=0;
				while(result%temp[i]==0){
					temp1++;
					result/=temp[i];
				}
				if(k>0)	cout << " ";
				cout << temp[i] << " " << temp1;
				k++;
			}
		}
		cout << endl;
	}
	return 0;
}
