#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	char line[1024], *ptr;
	int total=0, i=0, temp=0, mul=0, result=0;
	int coef[1024];
	while(cin.getline(line,1024)){
		ptr=line;
		coef[0]=atoi(ptr);
		total=1;
		while(*ptr){
			if(*ptr==' '){
				ptr++;
				coef[total++]=atoi(ptr);
			}
			ptr++;
		} 
		cin.getline(line,1024);
		ptr=line;
		temp=atoi(ptr); result=0; mul=1;
		for(i=total-1; i>=0; i--){
			result+=mul*coef[i];
			mul*=temp;
		}
		cout << result;
		while(*ptr){
			if(*ptr==' '){
				temp=atoi(ptr); result=0; mul=1;
				for(i=total-1; i>=0; i--){
					result+=mul*coef[i];
					mul*=temp;
				}	
				cout << " " << result;
			}
			ptr++;
		}
		cout << endl;
	}
	return 0;
}

