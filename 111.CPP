#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
		char line[1024];
		char *ptr;
		int state=0;
		int temp[32];
		int correct[32];
		int number=0;
		int count=0;
		while(cin.getline(line,1024)){
				ptr=line;
				temp[0]=atoi(ptr); count=1;
				while(*ptr){
						if(*ptr==' '){
								ptr++;
								temp[count++]=atoi(ptr);
						}
						ptr++;
				}
				if(count==1){
						number=temp[0];
						state=0;
				}
				else{
						if(!state){
								for(int i=0; i<number; i++)
										correct[temp[i]-1]=i+1;
								state=1;
						}
						else{
								int length[32][32];
								int temp1[32];
								for(int i=0; i<=number; i++) length[i][0]=0;
								for(int j=0; j<=number; j++) length[0][j]=0;
								for(int i=0; i<number; i++) temp1[temp[i]-1]=i+1;
								for(int i=1; i<=number; i++){
										for(int j=1; j<=number; j++){
												if(correct[i-1]==temp1[j-1])
														length[i][j]=length[i-1][j-1]+1;
												else if(length[i-1][j]<length[i][j-1])
														length[i][j]=length[i][j-1];
												else
														length[i][j]=length[i-1][j];
										}
								}
								cout << length[number][number] << endl;
						}
				}
		}
		return 0;
}
