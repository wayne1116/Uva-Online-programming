#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, flag=0, result=0;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a==0 && b==0) break;
		printf("%d %d ", a, b);
		if(a==1 && b==1) printf("Multiple\n");    
		else if(a==1) printf("Impossible\n");    
		else{
			flag=0;
			result=b;
			while(1){
				if(b==1) break;
				else if(a>b){
					flag=1;
					break;
				}
				result+=b/a;
				b=b/a+b%a;
			}
			if(flag) printf("Impossible\n");
			else printf("%d\n", result);
		}
	}
	return 0;
}
