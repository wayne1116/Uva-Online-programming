#include<iostream>
#include<set>
#include<cstdlib>
using namespace std;
int main()
{
	char line1[1024], line2[1024], *ptr;
	int count=0, num=0;
	set<int> set1, set2;
	set<int>::iterator it;
	while(cin.getline(line1,1024)){
		cin.getline(line2,1024);
		ptr=line1;
		set1.insert(atoi(ptr));
		while(*ptr){
			if(*ptr==' ' && *(ptr+1)>='0' && *(ptr+1)<='9'){
				ptr++; num=atoi(ptr);
				set1.insert(num);
			}
			ptr++;
		}
		ptr=line2;
		set2.insert(atoi(ptr));
		while(*ptr){
			if(*ptr==' ' && *(ptr+1)>='0' && *(ptr+1)<='9'){
				ptr++; num=atoi(ptr);
				set2.insert(num);
			}
			ptr++;
		}
		count=0;
		for(it=set1.begin(); it!=set1.end(); it++){
			if(set2.count(*it)) ++count;
		}
		if(count==set2.size() && count==set1.size()) cout << "A equals B" << endl;
		else if(count==set1.size()) cout << "A is a proper subset of B" << endl;
		else if(count==set2.size()) cout << "B is a proper subset of A" << endl;
		else if(count==0) cout << "A and B are disjoint" << endl;
		else cout << "I'm confused!" << endl; 
		set1.clear();
		set2.clear();
	}
	return 0;
}
