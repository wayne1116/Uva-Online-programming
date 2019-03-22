#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	char line[256], *ptr;
	int index=0;
	double x=0, y=0, number, temp;
	while(cin>>line){
		if(line[0]=='E') break;
		ptr=line;
		x=y=0; 
		while(*ptr){
			if(*ptr>='0'&&*ptr<='9'){
				number=atof(ptr);
				while(*ptr>='0' && *ptr<='9') ptr++;
				if(*(ptr+1)!=','&&*(ptr+1)!='.') number=sqrt(number*number/2.0);
				while(*ptr!='.'&&*ptr!=','){
					if(*ptr=='N') y+=number;
					else if(*ptr=='E') x+=number;
					else if(*ptr=='S') y-=number;
					else x-=number;
					ptr++;
				}
			}
			ptr++;
		}
		cout << "Map #" << ++index << endl;
		cout << "The treasure is located at (" << fixed << setprecision(3) << x << "," << y << ")." << endl;
		cout << "The distance to the treasure is " << fixed << setprecision(3) << sqrt(x*x+y*y) << "." << endl << endl;
	}
	return 0;
}
