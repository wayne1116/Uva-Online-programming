#include<iostream>
#include<cmath>
using namespace std;
int prim[100000];
int main()
{
	int i=0, j=0, limit=0, count=0, n=0;
	int find=0, start=0, end=0, middle=0;
	for(i=3; i<1000000; i++){
		if(i%2!=0){
			limit=sqrt(i);
			for(j=2; j<=limit; j++){
				if(i%j==0) break;
			}
			if(j>limit) prim[count++]=i;
		}
	}
	while(cin>>n && n){
		for(i=0; i<count; i++){
			if(n>prim[i]){
				find=n-prim[i];
				start=i; end=count;
				while(start<=end){
					middle=(start+end)/2;
					if(prim[middle]==find) break;
					else if(prim[middle]>find) end=middle-1;
					else start=middle+1;
				}
				if(start<=end) {
					cout << n << " = " << prim[i] << " + " << find << endl;
					break;
				} 
			}
			else break;
		}	
		if(i>=count) cout << "Goldbach's conjecture is wrong." << endl;
	}
	return 0;
}
