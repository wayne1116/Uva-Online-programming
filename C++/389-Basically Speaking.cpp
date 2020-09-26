#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	char line[1024], line1[1024], temp;
	int i=0, j=0, result=0, cur=0, next=0, len=0, number=0;
	while(cin>>line>>cur>>next){
		len=strlen(line);
		result=0;
		for(i=0; i<len; i++){
			if(line[i]>='0' && line[i]<='9') result+=(line[i]-48)*pow(cur,len-1-i);
			else result+=(line[i]-55)*pow(cur,len-1-i);
		}
		for(i=0; i<8; i++) line1[i]='\0';
		if(result==0) cout<<setw(7)<<0<<endl;
		else{
			i=0;
			while(result>0){
				number=result%next;
				if(number>9) line1[i]=55+number;
				else line1[i]=48+number;
				i++;
				result/=next;
			}
			if(i>7) cout<<setw(7)<<"ERROR"<<endl;
			else{
				for(j=0; j<i/2; j++){
					temp=line1[j];
					line1[j]=line1[i-j-1];
					line1[i-j-1]=temp;
				}
				line1[i]='\0';
				cout <<setw(7)<<line1<<endl;
			}
		}
	}
	return 0;
}
