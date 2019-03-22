#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	int temp, target, start, count, size, i, j, k, l;
	int result[32], num[32];
	
	while(getline(cin,str)){
		cout << str << endl;
		str+=' ';
		start=0; count=0;
		size=str.size();
		for(i=0; i<size; i++){
			if(str[i]==' '){
				num[count]=start;
				result[count]=start;
				start=0;
				++count;
			}
			else start=start*10+str[i]-48;
		}
		sort(result,result+count);
		 
		for(i=count-1; i>0; i--){
			if(result[i]!=num[i]){
				target=result[i];
				if(target!=num[0]){
					for(j=i-1; j>0; j--)if(target==num[j]) break;
					k=j; l=0;
					while(k>l){
						temp=num[k];
						num[k]=num[l];
						num[l]=temp;
						--k;
						++l;
					}
					cout << count-j << " ";
				}
				j=i; k=0;
				while(j>k){
					temp=num[j];
					num[j]=num[k];
					num[k]=temp;
					--j;
					++k;
				}
				cout << count-i << " ";
			}
		}
		cout << 0 << endl;
	}
	return 0;
}
