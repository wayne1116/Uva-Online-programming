#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i=0, j=0, limit=0, count=0, n=0, c=0, temp=0, start=0, b=0;
	int prim[1024]={1};
	count=1;
	for(i=2; i<=1000; i++){
		limit=sqrt(i);
		for(j=2; j<=limit; j++){
			if(i%j==0) break;
		}
		if(j>limit) prim[count++]=i;
	}
	while(cin>>n>>c){
		for(i=0; i<count; i++){
			if(prim[i]>n) break;
		}
		cout << n <<" "<<c<<":"; 
		if(i%2==0) b=c*2;
		else b=c*2-1;
		if(b>=i){
			for(j=0; j<i; j++) cout <<" "<<prim[j]; 
		}
		else{
			if(i%2==1) {
				temp=(b-1)/2;
				start=i/2-temp;
			} 
			else{
				temp=(b-2)/2;
				start=(i-1)/2-temp;
			}
			for(j=start; j<start+b; j++) cout<<" "<<prim[j];
		}
		cout << endl << endl;
	}
	return 0;
}
