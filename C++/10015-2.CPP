#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int prim[4096];
int main()
{
	int n=0, i=0, count=1, j=0, limit=0, temp;
	queue<int> qu;
	prim[0]=2;
	for(i=3; i<35000; i+=2){
		limit=sqrt(i);
		for(j=2; j<=limit; j++){
			if(i%j==0) break;
		}
		if(j>limit) prim[count++]=i;
	}
	while(cin>>n && n){
		for(i=1; i<=n; i++) qu.push(i);
		for(i=n; i>=2; i--){
			limit=(prim[n-i])%i;
			if(limit==0) limit=i;
			while(--limit){
				temp=qu.front();
				qu.pop();
				qu.push(temp);
			} 
			qu.pop();
		}
		cout << qu.front() << endl;
		while(!qu.empty())qu.pop();
	}
	return 0;
}
