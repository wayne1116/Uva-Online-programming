#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
		char command;
		while((cin>>command)){
				if(command=='#')
						break;
				string phonenumber;
				int starth;
				int startm;
				int endh;
				int endm;
				int start;
				int end;
				cin >> phonenumber >> starth >> startm >> endh >> endm;
				start=starth*60+startm;
				end=endh*60+endm;
				int stime1;
				int etime1;
				int stime2;
				int etime2;
				int stime3;
				int etime3;
				stime1=8*60; etime1=18*60;
				stime2=18*60; etime2=22*60;
				stime3=22*60; etime3=8*60;
				int result1;
				int result2;
				int result3;
				result1=result2=result3=0;
				if(start==end){
						result1=600;
						result2=240;
						result3=600;
				}
				else{
						while(start!=end){
								start=(start+1)%1440;
								if(start>stime1 && start<=etime1)
										result1++;
								else if(start>stime2 && start<=etime2)
										result2++;
								else if(start>stime3 || start<=etime3)
										result3++;
						}
				}
				float result;
				if(command=='A')
						result=0.1*result1+0.06*result2+0.02*result3;
				else if(command=='B')
						result=0.25*result1+0.15*result2+0.05*result3;
				else if(command=='C')
						result=0.53*result1+0.33*result2+0.13*result3;
				else if(command=='D')
						result=0.87*result1+0.47*result2+0.17*result3;
				else
						result=1.44*result1+0.80*result2+0.3*result3;
				cout << setw(10) << phonenumber
						<< setw(6) << result1
						<< setw(6) << result2
						<< setw(6) << result3
						<< setw(3) << command
						<< fixed << setw(8) << setprecision(2) << result << endl;
		}
		return 0;
}
