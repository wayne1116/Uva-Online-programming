#include<iostream>
#include<map>
using namespace std;
string str[1024];
int main()
{
	int a, num, len, i, j, Max, Min, size;
	string temp, result, temp1, temp2;
	map<string,int> mmap;
	
	cin >> a;
	cin.ignore();
	getline(cin,temp);
	while(a--){
		num=0;
		Max=0; Min=2147483647;
		while(getline(cin,str[num])&&str[num].size()>0){
			size=str[num].size();
			if(Min>size) Min=size;
			else if(Max<size) Max=size;
			++num;
		}
		len=Min+Max;
		mmap.clear();
		for(i=0; i<num; i++){
			for(j=i+1; j<num; j++){
				temp1=str[i]+str[j];
				temp2=str[j]+str[i];
				if(temp1.size()==len){
					if(mmap.find(temp1)==mmap.end()) mmap[temp1]=1;
					else ++mmap[temp1];
				}
				if(temp2.size()==len){
					if(mmap.find(temp2)==mmap.end()) mmap[temp2]=1;
					else ++mmap[temp2];
				}
			}
		}
		Max=0;
		for(auto iter:mmap){
			if(iter.second>Max){
				Max=iter.second;
				result=iter.first;
			}
		}
		cout << result << endl;
		if(a) cout << endl;
	}
	return 0;	
} 
