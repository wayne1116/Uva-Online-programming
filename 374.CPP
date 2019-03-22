#include<stdio.h>
#include<stdlib.h>
long long rec(long long a, long long b, long long c)
{
	long long temp;
	if(b==1) return a%c;
	if(b%2==0){
		temp=rec(a,b/2,c);
		return (temp*temp)%c;
	} 
	return (rec(a,b-1,c)*a)%c;
}
int main()
{
	long long a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF){
		if(b==0) printf("%lld\n", 1%c); 
		else printf("%lld\n", rec(a,b,c));
	} 
	return 0;
}
