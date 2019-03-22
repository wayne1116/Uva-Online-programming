#include<iostream>
#include<map>
using namespace std;
int result[1000000];
int result1[1000000];
int main()
{
	int number=0, i=0, j=0, k=0, size=0, count=1, temp=0;
	int result2[100000];
	map<int,int> mmap;
	map<int,int>::iterator it;
	
	cin >> number ;
	mmap.insert(pair<int,int>(number,count));
	result[i]=count; result1[i]=number; count++; i++;
	while(cin>>number){
		it=mmap.lower_bound(number);
		result1[i]=number;
		if(it==mmap.end()){
			mmap.insert(pair<int,int>(number,count));
			result[i]=count++; 
		}
		else{
			temp=it->second;
			mmap.erase(it->first);
			mmap.insert(pair<int,int>(number,temp));
			result[i]=temp;	
		}
		i++;
	}
	size=mmap.size();
	cout << size << endl;
	cout << "-" << endl;
	for(j=i-1, k=0; j>=0; j--){
		if(size==result[j]){
			result2[k++]=result1[j];
			size--;
		}
	} 
	for(j=k-1; j>=0; j--) cout << result2[j] << endl;
	return 0;
}
