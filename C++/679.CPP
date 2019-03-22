#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0, result=0, n=0, m=0;
	scanf("%d",&a);
	while(a--){
		scanf("%d%d",&n,&m);
		result=1;
		for(i=1; i<n; i++){
			if(m%2==0){
				result=result*2+1;
				m/=2;
			}
			else{
				result*=2;
				m=(m+1)/2;
			}
		}
		printf("%d\n", result);
	}
	scanf("%d",&a);
	return 0;
}
