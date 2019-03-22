#include<iostream>
#include<map>
using namespace std;
int main()
{
	int a=0, b=0, count=0, i=0;
	int result[1024], state=0;
	map<int,int> mmap;
	map<int,int>::iterator it;
	
	while(cin>>a>>b &&a&&b){
		count=0;
		mmap.clear();
		while(1){ 
			if(a==0){
				cout << ".";
				for(i=0; i<count; i++){
					if((i+1)%50==0) cout << "\n";
					cout << result[i];
				}
				cout << endl;
				cout << "This expansion terminates." << endl;
				break;
			}
			it=mmap.find(a);
			if(it==mmap.end())
				mmap.insert(pair<int,int>(a,count));
			else{
				cout << ".";
				for(i=0; i<count; i++){
					if((i+1)%50==0) cout << "\n";
					cout << result[i];
				}
				cout << endl;
				cout << "The last " << count-it->second << " digits repeat forever." << endl; 
				break;
			}
			a*=10;
			while(a<b){
				if(mmap.find(a)!=mmap.end()) break;
				else mmap.insert(pair<int,int>(a,count+1));
				result[count++]=0;
				a*=10;
			}
			result[count++]=a/b;
			a=a%b;
		}
		cout << endl; 
	}
	return 0;
}
