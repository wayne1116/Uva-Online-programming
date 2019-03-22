#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
bool cmp(int &x, int &y)
{
	return y>x;
}
int main()
{
	int i=0, j=0;
	int number[10000];
	while(scanf("%d",&number[i++])!=EOF){
		sort(number,number+i,cmp);
		if(i%2==1) printf("%d\n", number[i/2]);
		else printf("%d\n", (number[i/2]+number[i/2-1])/2);
	}
	return 0;
}
