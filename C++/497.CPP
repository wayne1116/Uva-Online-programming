#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a=0, count=0, num=0, i=0, len=0;
	int left=0, right=0, middle=0, next=0;
	int result[1024], order[1024], temp[1024], parent[1024];
	string line;
	
	cin >> a;
	cin.ignore(); cin.ignore();
	while(a--){
		count=0; len=0; result[0]=2147483647;
		while(getline(cin,line)){
			if(line=="") break;
			num=0;
			for(i=0; i<line.size(); i++) num=num*10+line[i]-48;
			temp[count]=num;
			
			left=0; right=len;
			while(left<=right){
				middle=(left+right)/2;
				if(result[middle]==num)break;
				else if(result[middle]>num) right=middle-1;
				else left=middle+1;
			}
			if(left>right){
				if(left>=len){
					result[len]=num;
					order[len]=count;
					if(len!=0) parent[count]=order[len-1];
					else parent[count]=-1;
					++len;
				}
				else{
					result[left]=num;
					order[left]=count;
					parent[count]=order[left-1];
				}
			}
			count++;
		}
		next=order[len-1];
		for(i=len-1; i>=0; i--){
			result[i]=temp[next];
			next=parent[next];
		}
		 
		cout << "Max hits: "<< len << endl;
		for(i=0; i<len; i++) cout << result[i] << endl;
		if(a) cout << endl;
	}
	return 0;
}
