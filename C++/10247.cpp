#include<iostream>
const int Max=10000;
using namespace std;

int main()
{
    int n, m, i, j, k; 
    int mul1, mul2, mul3, temp1;
    int result[Max];
    int temp[Max];
	
    while(cin>>n>>m){
        if(n==1) cout << 1 << endl;
	else{
	    mul1=n;
	    for(i=0; i<m; i++) mul1*=n;
	    mul1=(mul1-1)/(n-1)-1;
	    mul2=mul1/n;
	    for(i=0; i<mul1; i++) temp[i]=i+1;
	    mul3=n;
	    for(i=1; i<m; i++){
	        for(j=0; j<mul3; j++){
		    for(k=mul1-1; k>=0; k--){
			if(temp[k]%mul2==0){
			    temp[k]/=mul2;
			    break;
		        }
		    }
		}
		mul3*=n;
		mul2/=n;
	    }
	    for(i=0; i<Max; i++) result[i]=0;
		result[0]=1;
		for(i=mul1-1; i>0; i--){
		    if(temp[i]>1){
			for(j=0; j<Max; j++) result[j]*=temp[i];
			for(j=0; j<Max-1; j++){
			    if(result[j]>9){
				temp1=result[j]/10;
				result[j]%=10;
				result[j+1]+=temp1;
			    }
		        }
		    }
	        }
		for(i=Max-1; i>=0; i--)if(result[i]!=0) break;
		for(j=i; j>=0; j--) cout << result[j];
		cout << endl;
	    }
    }
    return 0;
} 
