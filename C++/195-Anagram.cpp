#include <iostream>
#include <string>
#include<algorithm>
#include<cstring>
using namespace std;

void recPermute(string soFar,string rest)
{
    	string check_repeat="\0";
    	string next="\0";

    	if(rest == "") {
        	cout << soFar << endl;
    	} else {
        	for(int i = 0; i < rest.length(); i++) {
            	check_repeat = next;
            	next = soFar + rest[i];
            
            	string remaining = rest.substr(0,i) + rest.substr(i+1);

            	if(next != check_repeat)
                	recPermute(next, remaining);
        	}            
    	}
}
bool cmp(char &x, char &y)
{
	if(x>='A' && x<='Z' && y>='a' && y<'z'){
		if(x+32==y) return y>x;
		return y>x+32;
	}
	else if(x>='a' && x<='z' && y>='A' && y<='Z'){
		if(x==y+32) return y>x;
		return y+32>x;
	}
	return y>x;
}
int main(void)
{
	int a=0;
	string line;
    	cin >> a;
	while(a--){
		cin >> line;
		sort(line.begin(),line.end(),cmp);
		recPermute("",line);
	} 
    	return 0;
}
