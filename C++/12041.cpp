#include<iostream>
using namespace std;
long long int fb[64];
void print(int n, int start, int end)
{
	if(n==0||n==1) cout << n;
	else{ 
		if(end<fb[n-2]) print(n-2,start,end);
		else if(start<fb[n-2]){
			print(n-2,start,fb[n-2]-1);
			print(n-1,0,end-fb[n-2]);
		}
		else print(n-1,start-fb[n-2],end-fb[n-2]);
	}
}
int main()
{
	int i, a, n, start, end;
	fb[0]=fb[1]=1;
	for(i=2; i<49; i++) fb[i]=fb[i-1]+fb[i-2];
	cin >> a;
	while(a--){
		cin >> n >> start >> end;
		//scanf("%d %d %d",&n,&start,&end);
		if(n>=48) n=48-n%2;
		print(n,start,end);
		//printf("\n");
		cout << endl;
	}
	return 0;
}
